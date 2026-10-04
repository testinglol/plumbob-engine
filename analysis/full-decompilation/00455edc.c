
void FUN_00455edc(undefined4 param_1,int param_2,int param_3,char param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined **local_328;
  int local_324;
  undefined1 local_31c [256];
  undefined **local_21c;
  int local_218;
  undefined1 local_210 [256];
  undefined **local_110;
  int local_10c;
  undefined1 local_104 [256];
  
  *(undefined2 *)(param_2 + 8) = 0;
  **(undefined1 **)(param_2 + 4) = 0;
  *(undefined2 *)(param_3 + 8) = 0;
  **(undefined1 **)(param_3 + 4) = 0;
  uVar1 = FUN_004705f2(param_1,0xffffffff);
  FUN_0046f824(local_31c,0,0x100);
  local_328 = &PTR_FUN_00666524;
  FUN_0046f847(uVar1,0xffffffff);
  FUN_0046f824(local_210,0,0x100);
  local_21c = &PTR_FUN_00666524;
  iVar2 = FUN_0046fab1(&DAT_006c145c,0);
  if (param_4 == '\0') {
    FUN_0046f917(&local_328,iVar2);
  }
  else if (iVar2 != -1) {
    FUN_0046f847(local_324 + 1 + iVar2,0xffffffff);
  }
  iVar2 = FUN_0046fab1(&DAT_006c0fdc,0);
  if (iVar2 == -1) {
    FUN_0046f917(&local_21c,0xffffffff);
  }
  else {
    FUN_0046f917(&local_21c,iVar2);
    FUN_0046f9f6();
    FUN_0046f824(local_104,0,0x100);
    local_110 = &PTR_FUN_00666524;
    FUN_0046f847(local_218 + 1 + iVar2,0xffffffff);
    iVar2 = FUN_0046fab1(&DAT_006c42ec,0);
    if (iVar2 != -1) {
      FUN_0046f917(&local_110,iVar2 + 1);
      FUN_0046f9f6();
      FUN_0046f847(local_10c + 1 + iVar2,0xffffffff);
      return;
    }
    FUN_0046f8e4(&local_110);
  }
  FUN_0046f9f6();
  return;
}

