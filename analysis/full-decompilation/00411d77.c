
void __thiscall FUN_00411d77(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00411de1(param_3);
  for (puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + iVar1 * 4); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar2) {
    iVar1 = FUN_0046f973(param_3);
    if (iVar1 == 0) break;
  }
  param_2[1] = param_1;
  *param_2 = puVar2;
  return;
}

