
int __fastcall FUN_0060783f(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  for (puVar2 = *(undefined4 **)*param_1; puVar2 != (undefined4 *)*param_1;
      puVar2 = (undefined4 *)*puVar2) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

