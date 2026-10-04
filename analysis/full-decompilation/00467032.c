
void __fastcall FUN_00467032(int param_1)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  undefined *puVar5;
  
  FUN_005bc69b(s_Room_Statistics_006c49c4);
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    puVar3 = *(ushort **)(iVar2 + 0x14);
    if (*(int *)(puVar3 + 0x1a) != 0) {
      puVar5 = &DAT_006c08dc;
      uVar4 = (uint)*puVar3;
      FUN_005bc69b(s______________Room___006c49b0);
      FUN_005bc69b(uVar4);
      FUN_005bc69b(puVar5);
      FUN_0046815a();
    }
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 4);
  }
  return;
}

