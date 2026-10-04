
void FUN_004eea6b(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  
  *(undefined2 *)(param_3 + 2) = 0;
  *(undefined1 *)param_3[1] = 0;
  FUN_00425531(param_3);
  if (param_1 != 0) {
    FUN_0046f847(param_1,0xffffffff);
  }
  iVar2 = (**(code **)*param_3)();
  cVar1 = *(char *)(param_3[1] + iVar2 + -1);
  if ((cVar1 != '/') && (cVar1 != '\\')) {
    FUN_0046fa24(0x2f);
  }
  if (param_2 != 0) {
    FUN_0046f847(param_2,0xffffffff);
  }
  return;
}

