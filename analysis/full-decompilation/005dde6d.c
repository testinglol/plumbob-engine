
void __thiscall FUN_005dde6d(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  
  iVar1 = param_1[0x1a];
  param_1[0x1a] = param_2;
  if (iVar1 != param_2) {
    cVar2 = (**(code **)(*param_1 + 0x8c))(1);
    if (cVar2 != '\0') {
      FUN_005db0b7();
    }
  }
  return;
}

