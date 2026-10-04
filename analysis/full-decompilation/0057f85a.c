
byte __fastcall FUN_0057f85a(int param_1)

{
  byte bVar1;
  
  bVar1 = **(byte **)(param_1 + 0x19c);
  *(byte **)(param_1 + 0x19c) = *(byte **)(param_1 + 0x19c) + 1;
  if (0x7f < bVar1) {
    (**(code **)(DAT_006f6a78 + 200))(param_1,s_Illegal_Register_Id_006d018c);
    return 1;
  }
  return bVar1;
}

