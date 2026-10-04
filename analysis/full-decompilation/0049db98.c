
void __fastcall
FUN_0049db98(int param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6,
            undefined4 *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  iVar5 = DAT_006f0bd4;
  iVar4 = DAT_006f0bbc;
  puVar6 = (undefined4 *)(DAT_006f0bbc * param_2 + param_1 * 2 + DAT_006f0bcc);
  puVar7 = (undefined4 *)(DAT_006f0bd4 * param_2 + param_1 * 2 + DAT_006f0bd0);
  uVar8 = param_2 + param_3 & 1;
  if (0 < param_3) {
    do {
      iVar2 = *param_5;
      *param_5 = param_5[1] + iVar2;
      iVar3 = *param_6;
      *param_6 = iVar3 + param_6[1];
      iVar2 = uVar8 + (iVar2 >> 8) * 2;
      uVar8 = uVar8 ^ 1;
      puVar1 = (undefined4 *)(*(int *)(param_4 + (iVar3 >> 8) * 4) + iVar2 * 8);
      *puVar6 = *puVar1;
      puVar6[1] = puVar1[1];
      puVar6 = (undefined4 *)((int)puVar6 + iVar4);
      *puVar7 = *param_7;
      puVar7[1] = param_7[1];
      puVar7 = (undefined4 *)((int)puVar7 + iVar5);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}

