
void __fastcall FUN_00507e26(int *param_1)

{
  char cVar1;
  
  if ((int *)param_1[0x39] != (int *)0x0) {
    cVar1 = (**(code **)(*(int *)param_1[0x39] + 0x8c))(1);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 300))(1,param_1[0x39]);
    }
  }
  return;
}

