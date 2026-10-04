
undefined4 __fastcall FUN_005236c6(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x174))(0,0);
    (**(code **)(*param_1 + 0xcc))(0);
    FUN_005a5e48(0);
    param_1[0x3b] = 0;
    param_1[0x3c] = 0;
    param_1[0x39] = 0;
    param_1[0x3a] = 0;
    FUN_005a5e48(0);
  }
  return 1;
}

