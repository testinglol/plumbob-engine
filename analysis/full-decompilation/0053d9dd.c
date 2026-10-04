
void __thiscall FUN_0053d9dd(int param_1,uint param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x30);
  if (iVar2 != *(int *)(param_1 + 0x34)) {
    do {
      iVar1 = *(int *)(param_1 + 0x18);
      if (*(ushort *)(iVar2 + 2 + iVar1 * 2) == param_2) {
        *(undefined2 *)(iVar2 + 2 + iVar1 * 2) = param_3;
        uVar3 = (uint)(*(int *)(param_1 + 0x18) == 0);
LAB_0053da27:
        *(undefined2 *)(iVar2 + 2 + uVar3 * 2) = param_3;
      }
      else if (*(ushort *)(iVar2 + 2 + (uint)(iVar1 == 0) * 2) == param_2) {
        *(undefined2 *)(iVar2 + 2 + (uint)(iVar1 == 0) * 2) = param_3;
        uVar3 = *(uint *)(param_1 + 0x18);
        goto LAB_0053da27;
      }
      iVar2 = iVar2 + 6;
    } while (iVar2 != *(int *)(param_1 + 0x34));
  }
  return;
}

