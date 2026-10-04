
void __fastcall FUN_00507e55(int *param_1)

{
  char cVar1;
  
  if ((int *)param_1[0x3a] != (int *)0x0) {
    cVar1 = (**(code **)(*(int *)param_1[0x3a] + 0x8c))(1);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 300))(1,param_1[0x3a]);
    }
  }
  return;
}

