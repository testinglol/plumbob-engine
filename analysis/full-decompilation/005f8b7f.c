
undefined4 * FUN_005f8b7f(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_006762c0;
  extraout_ECX[1] = 0;
  FUN_005ecffb();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0xf] = 0;
  extraout_ECX[0x10] = 0;
  extraout_ECX[0x413] = 0;
  extraout_ECX[0x414] = 0;
  extraout_ECX[0x415] = 0;
  extraout_ECX[0x416] = 0;
  extraout_ECX[0x418] = 0;
  extraout_ECX[0x419] = 0;
  *(undefined1 *)(extraout_ECX + 0x41a) = 0;
  FUN_005d48d9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x41e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1079) = 0;
  *extraout_ECX = &PTR_FUN_00676260;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  *(undefined2 *)((int)extraout_ECX + 0x107a) = 1;
  *(undefined2 *)(extraout_ECX + 0x41f) = 2;
  *(undefined4 *)((int)extraout_ECX + 0x107e) = 0xac44;
  *(undefined4 *)((int)extraout_ECX + 0x1082) = 0x2b110;
  *(undefined2 *)(extraout_ECX + 0x422) = 0x10;
  *(undefined2 *)((int)extraout_ECX + 0x1086) = 4;
  *(undefined2 *)((int)extraout_ECX + 0x108a) = 0;
  return extraout_ECX;
}

