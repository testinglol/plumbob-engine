
uint FUN_004f5a42(void)

{
  byte in_ID;
  
  return (uint)((in_ID & 1) != 1) * 0x200000 ^ (uint)(in_ID & 1) * 0x200000;
}

