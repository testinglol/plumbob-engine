
void __thiscall FUN_004aaca7(int param_1,int *param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  uVar1 = *(undefined2 *)(param_1 + 0x408);
  iVar2 = param_2[2];
  iVar4 = param_2[3] - param_2[1];
  iVar7 = DAT_006f0bd4 >> 1;
  iVar6 = DAT_006f0bd0 + param_2[1] * iVar7 * 2;
  if (0 < iVar4) {
    iVar3 = *param_2;
    param_2 = (int *)iVar4;
    do {
      if (iVar3 < iVar2 + -1) {
        puVar8 = (undefined4 *)(iVar6 + iVar3 * 2);
        for (uVar5 = ((iVar2 + -1) - iVar3) + 1U >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar8 = CONCAT22(uVar1,uVar1);
          puVar8 = puVar8 + 1;
        }
      }
      iVar6 = iVar6 + iVar7 * 2;
      param_2 = (int *)((int)param_2 + -1);
    } while (param_2 != (int *)0x0);
  }
  return;
}

