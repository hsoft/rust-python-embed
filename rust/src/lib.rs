#[no_mangle]
pub extern "C" fn triple(value: u32) -> u32 {
    value * 3
}

