
void __thiscall FUN_0049da72(int param_1,int param_2,char param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if (*(int *)(param_1 + 0x37c) == 0) {
    if (param_3 == '\0') {
      uVar1 = *(undefined2 *)(param_1 + 0x18);
      for (iVar8 = *(int *)(param_2 + 0xc); iVar8 != *(int *)(param_2 + 0x10); iVar8 = iVar8 + 0x28)
      {
        uVar2 = *(undefined2 *)(iVar8 + 0x20);
        iVar9 = *(int *)(iVar8 + 0x1c) * 2;
        iVar6 = *(int *)(iVar8 + 0x24);
        puVar3 = (undefined2 *)(*(int *)(iVar8 + 0x18) * DAT_006f0bbc + iVar9 + DAT_006f0bcc);
        puVar5 = (undefined2 *)(*(int *)(iVar8 + 0x18) * DAT_006f0bd4 + iVar9 + DAT_006f0bd0);
        if (0 < iVar6) {
          do {
            *puVar3 = uVar2;
            puVar3 = (undefined2 *)((int)puVar3 - DAT_006f0bbc);
            *puVar5 = uVar1;
            puVar5 = (undefined2 *)((int)puVar5 - DAT_006f0bd4);
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
    else {
      uVar1 = *(undefined2 *)(param_1 + 0x18);
      for (iVar8 = *(int *)(param_2 + 0xc); iVar8 != *(int *)(param_2 + 0x10); iVar8 = iVar8 + 0x28)
      {
        iVar6 = *(int *)(iVar8 + 0x18);
        iVar9 = *(int *)(iVar8 + 0x1c);
        iVar10 = (iVar6 - *(int *)(iVar8 + 0x24)) + 1;
        if ((((-1 < iVar9) && (iVar9 < DAT_006f0bc6)) && (iVar7 = (int)DAT_006f0bc0, iVar7 <= iVar6)
            ) && (iVar4 = (int)DAT_006f0bc4, iVar10 < iVar4)) {
          if (iVar10 < iVar7) {
            iVar10 = iVar7;
          }
          if (iVar4 <= iVar6) {
            iVar6 = iVar4 + -1;
          }
          puVar3 = (undefined2 *)(DAT_006f0bbc * iVar6 + iVar9 * 2 + DAT_006f0bcc);
          puVar5 = (undefined2 *)(DAT_006f0bd4 * iVar6 + iVar9 * 2 + DAT_006f0bd0);
          uVar2 = *(undefined2 *)(iVar8 + 0x20);
          if (-1 < iVar6 - iVar10) {
            iVar6 = (iVar6 - iVar10) + 1;
            do {
              *puVar3 = uVar2;
              puVar3 = (undefined2 *)((int)puVar3 - DAT_006f0bbc);
              *puVar5 = uVar1;
              puVar5 = (undefined2 *)((int)puVar5 - DAT_006f0bd4);
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
      }
    }
  }
  return;
}

