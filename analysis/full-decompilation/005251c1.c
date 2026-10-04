
undefined4 __fastcall FUN_005251c1(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x36] = 0;
  }
  FUN_005dbf4d();
  return 1;
}

