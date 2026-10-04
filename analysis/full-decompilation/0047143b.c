
void __thiscall FUN_0047143b(int param_1,uint param_2,undefined4 param_3,char param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined4 local_10;
  
  cVar4 = *(char *)(param_1 + 0x5d);
  if (param_4 != -1) {
    cVar4 = param_4;
  }
  iVar8 = cVar4 * 0xc;
  piVar6 = (int *)(*(int *)(param_1 + 0x6c) + iVar8);
  if ((*(int *)(*(int *)(param_1 + 0x6c) + 4 + iVar8) - *piVar6) / 0xc + 1U < param_2) {
    param_2 = (piVar6[1] - *piVar6) / 0xc + 1;
  }
  if ((int)param_2 < 1) {
    param_2 = 1;
  }
  FUN_004716e0();
  piVar6 = (int *)(*(int *)(param_1 + 0x6c) + iVar8);
  iVar5 = (piVar6[1] - *piVar6) / 0xc;
  if ((int)param_2 < iVar5) {
    iVar7 = iVar5 * 0xc;
    iVar5 = iVar5 - param_2;
    do {
      iVar3 = *(int *)(*(int *)(param_1 + 0x6c) + iVar8);
      puVar1 = (undefined4 *)(iVar7 + -0x18 + iVar3);
      puVar2 = (undefined4 *)(iVar7 + -0xc + iVar3);
      *puVar2 = *puVar1;
      puVar2[1] = puVar1[1];
      puVar2[2] = puVar1[2];
      iVar7 = iVar7 + -0xc;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  local_10 = CONCAT31(local_10._1_3_,0xff);
  puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x6c) + iVar8) + -0xc + param_2 * 0xc);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = local_10;
  FUN_0047132c(param_2,param_3,cVar4);
  return;
}

