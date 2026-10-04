
void FUN_00480472(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar2;
  char *pcVar3;
  undefined **local_110 [2];
  short local_108;
  undefined1 local_104 [256];
  
  FUN_0046fa24(0x28);
  iVar2 = 0;
  if ((*(byte *)(param_1 + 1) & 1) == 0) {
    sVar1 = FUN_004021ff(param_4);
    if (sVar1 == 2) {
      iVar2 = FUN_00401f6f();
    }
    pcVar3 = s_Private__006c57e4;
  }
  else {
    iVar2 = FUN_00401f73();
    pcVar3 = s_Global__006c57f0;
  }
  FUN_0046f847(pcVar3,0xffffffff);
  FUN_0046f824(local_104,0,0x100);
  local_110[0] = &PTR_FUN_00666524;
  if (iVar2 != 0) {
    FUN_00465b21(local_110,iVar2,CONCAT22(extraout_var,*param_1),
                 CONCAT22(extraout_var,(ushort)*(byte *)(param_1 + 2)));
  }
  if (local_108 == 0) {
    FUN_0046f847(&DAT_006c107c,0xffffffff);
  }
  else {
    FUN_0046f917(local_110,0xffffffff);
  }
  FUN_0046f847(&DAT_006c25a8,0xffffffff);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0xde,
               CONCAT22(extraout_var_00,(ushort)*(byte *)((int)param_1 + 5)) + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  FUN_0046fa24(0x29);
  return;
}

