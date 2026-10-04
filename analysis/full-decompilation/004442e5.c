
void FUN_004442e5(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  uVar2 = *(undefined4 *)(*(int *)(param_2 + 0x11c) + 0x18);
  puVar4 = &DAT_006c3cd4;
  iVar1 = (int)*(short *)(param_2 + 0xf0);
  puVar3 = &DAT_006c0fdc;
  FUN_005bc69b(&DAT_006c3cd0);
  FUN_005bc69b(uVar2);
  FUN_005bc69b(puVar3);
  FUN_005bc69b(iVar1);
  FUN_005bc69b(puVar4);
  return;
}

