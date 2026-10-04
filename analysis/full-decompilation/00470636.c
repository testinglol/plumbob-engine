
void __thiscall FUN_00470636(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = 1;
  iVar1 = FUN_0046fbe5(0xffffffff);
  if (0 < iVar1) {
    do {
      puVar2 = (undefined1 *)FUN_004705f2(iVar4,0xffffffff);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_006de560;
      }
      FUN_004704a5(iVar4,puVar2,0xffffffff);
      iVar4 = iVar4 + 1;
      iVar1 = FUN_0046fbe5(0xffffffff);
    } while (iVar4 <= iVar1);
  }
  while( true ) {
    iVar4 = FUN_0046fbe5(0xffffffff);
    iVar1 = FUN_0046fbe5(0xffffffff);
    if (iVar1 <= iVar4) break;
    uVar5 = 0xffffffff;
    uVar3 = FUN_0046fbe5(0xffffffff);
    FUN_0047053c(uVar3,uVar5);
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 0x54) = 0;
  FUN_0046f8e4(param_2 + 8);
  return;
}

