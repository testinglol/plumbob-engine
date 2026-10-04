
void __thiscall
FUN_0049d914(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int *param_7,int *param_8)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_5 < 1) || (*(int *)(param_1 + 0x370) == 0)) {
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_2 + 4);
  }
  else {
    FUN_0049d9fe(*(int *)(param_1 + 0x374),*(int *)(param_1 + 0x370) + *(int *)(param_1 + 0x374));
    iVar4 = *(int *)(param_2 + 0xc);
    if (iVar4 != *(int *)(param_2 + 0x10)) {
      do {
        *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0xc) + param_3;
        iVar2 = __ftol();
        *(int *)(iVar4 + 0x18) = iVar2 + param_4;
        *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(iVar4 + 8);
        if (*(char *)(param_1 + 0x378) != '\0') {
          piVar1 = (int *)(iVar4 + 0x24);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            *(undefined4 *)(iVar4 + 0x24) = 1;
          }
        }
        iVar3 = *(int *)(iVar4 + 0x18) - param_4;
        iVar2 = (param_7[1] * iVar3 + *param_7 >> 8) + *(int *)(iVar4 + 0x14);
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        if (*(int *)(param_1 + 0x4c) <= iVar2) {
          iVar2 = *(int *)(param_1 + 0x4c) + -1;
        }
        iVar3 = iVar3 * param_8[1] + *param_8 >> 8;
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        if (*(int *)(param_1 + 0x7c) <= iVar3) {
          iVar3 = *(int *)(param_1 + 0x7c) + -1;
        }
        iVar5 = iVar4 + 0x28;
        *(undefined2 *)(iVar4 + 0x20) =
             *(undefined2 *)(*(int *)(*(int *)(param_1 + 0x70) + iVar3 * 4) + iVar2 * 0x10);
        iVar4 = iVar5;
      } while (iVar5 != *(int *)(param_2 + 0x10));
    }
  }
  return;
}

