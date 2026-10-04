
void FUN_005876ac(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  while( true ) {
    iVar1 = FUN_0046fbe5(0xffffffff);
    uVar3 = 0xffffffff;
    if (param_1 <= iVar1) break;
    puVar2 = &DAT_006de560;
    iVar1 = FUN_0046fbe5(0xffffffff);
    FUN_0047057a(iVar1 + 1,puVar2,uVar3);
  }
  FUN_004704a5(param_1,param_2,0xffffffff);
  return;
}

