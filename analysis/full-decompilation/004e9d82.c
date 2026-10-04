
void FUN_004e9d82(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined **local_110;
  char *local_10c;
  undefined1 local_104 [256];
  
  if (param_1 < 0) {
    return;
  }
  if ((DAT_006f264c - DAT_006f2648) / 0x44 <= param_1) {
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  cVar1 = (**(code **)(*piVar2 + 0x84))(0xffffffff);
  if (cVar1 == '\0') {
    iVar3 = FUN_004e8a7a();
    FUN_00406466(0,DAT_00666580);
    if (iVar3 == 0) {
      return;
    }
    uVar4 = thunk_FUN_00457ea7();
    FUN_005d499c(uVar4);
    iVar3 = FUN_004ea79e(param_1);
    iVar3 = FUN_00425db3((int)*(short *)(iVar3 + 0x7a));
    if (iVar3 == 0) {
      return;
    }
    FUN_0046f824(local_104,0,0x100);
    local_110 = &PTR_FUN_00666524;
    FUN_004102d4(&local_110);
    FUN_004015e4(0x20);
    sVar5 = _strlen(local_10c);
    pcVar6 = local_10c + sVar5;
  }
  else {
    FUN_00406466(0,DAT_00666580);
    iVar3 = FUN_004ea79e(param_1);
    iVar3 = FUN_00425db3((int)*(short *)(iVar3 + 0x7a));
    if (iVar3 != 0) {
      FUN_0046f824(local_104,0,0x100);
      local_110 = &PTR_FUN_00666524;
      FUN_004102d4(&local_110);
      FUN_005d4bbf(local_10c);
      FUN_004015e4(0x20);
    }
    iVar3 = FUN_004e8a7a();
    if (iVar3 == 0) {
      return;
    }
    puVar7 = (undefined4 *)thunk_FUN_00457ea7();
    pcVar6 = (char *)puVar7[1];
    local_10c = (char *)*puVar7;
  }
  FUN_00412d8a(local_10c,pcVar6);
  return;
}

