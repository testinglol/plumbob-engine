
void __fastcall FUN_00512263(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    param_1[0x36] = 0;
    param_1[0x37] = 0;
    if (*(char *)((int)param_1 + 0x119) != '\0') {
      FUN_005dae65(param_1);
      *(undefined1 *)((int)param_1 + 0x119) = 0;
    }
  }
  FUN_005dbf4d();
  return;
}

