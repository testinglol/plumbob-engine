
int __thiscall FUN_0047cc9a(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  for (; param_2 < 0; param_2 = param_2 + iVar1) {
  }
  for (; iVar1 <= param_2; param_2 = param_2 - iVar1) {
  }
  for (; param_3 < 0; param_3 = param_3 + iVar2) {
  }
  for (; iVar2 <= param_3; param_3 = param_3 - iVar2) {
  }
  return *(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) + param_3;
}

