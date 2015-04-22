#![feature(std_misc)]
use std::sync::{StaticMutex, MUTEX_INIT};

const STACK_COUNT: usize = 42;
static mut STACK: [u32; STACK_COUNT] = [0; STACK_COUNT];
static mut STACK_INDEX: usize = 0;
static LOCK: StaticMutex = MUTEX_INIT;

#[no_mangle]
pub extern "C" fn triple(value: u32) -> u32 {
    value * 3
}

// Returns zero for success, non-zero for error
#[no_mangle]
pub extern "C" fn stack_push(value: u32) -> u32 {
    unsafe {
        let _guard = match LOCK.lock() {
            Ok(guard) => guard,
            Err(_) => { return 2; },
        };
        if STACK_INDEX == STACK_COUNT {
            return 1;
        }
        STACK[STACK_INDEX] = value;
        STACK_INDEX += 1;
    }
    0
}

// 0 as error values? Yeah, I know...
#[no_mangle]
pub extern "C" fn stack_pull() -> u32 {
    unsafe {
        let _guard = match LOCK.lock() {
            Ok(guard) => guard,
            Err(_) => { return 0; },
        };
        if STACK_INDEX == 0 {
            return 0;
        }
        STACK_INDEX -= 1;
        STACK[STACK_INDEX]
    }
}
