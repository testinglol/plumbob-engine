
undefined4 __fastcall FUN_0052772d(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    if (param_1[0x4d] != 0) {
      FUN_005dae65(param_1);
    }
    (**(code **)(*param_1 + 0x90))(1,0);
    (**(code **)(*param_1 + 0x174))(0,0);
    (**(code **)(*param_1 + 0xcc))(0);
  }
  return 1;
}

