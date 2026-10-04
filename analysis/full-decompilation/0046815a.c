
void __fastcall FUN_0046815a(ushort *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined *puVar8;
  
  puVar4 = &DAT_006c4a0c;
  if (*(int *)(param_1 + 0x1a) == 0) {
    puVar4 = &DAT_006c4a08;
  }
  puVar8 = &DAT_006c08dc;
  uVar3 = (uint)*param_1;
  iVar1 = (*(int *)(param_1 + 4) - *(int *)(param_1 + 2)) / 3;
  pcVar7 = s___TileCount___006c49f8;
  iVar2 = (*param_1 >> 10 & 3) + 1;
  pcVar6 = s___Level___006c49ec;
  pcVar5 = s___Used__006c49e0;
  FUN_005bc69b(s_ID___006c49d8);
  FUN_005bc69b(uVar3);
  FUN_005bc69b(pcVar5);
  FUN_005bc69b(puVar4);
  FUN_005bc69b(pcVar6);
  FUN_005bc69b(iVar2);
  FUN_005bc69b(pcVar7);
  FUN_005bc69b(iVar1);
  FUN_005bc69b(puVar8);
  return;
}

