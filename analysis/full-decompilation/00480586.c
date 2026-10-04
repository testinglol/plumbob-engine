
void FUN_00480586(undefined2 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined4 uVar1;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 uVar2;
  undefined1 local_210 [256];
  undefined **local_110 [2];
  short local_108;
  undefined1 local_104 [256];
  
  FUN_0046f824(local_210,0,0x100);
  FUN_0047e457(*(undefined4 *)(param_2 + 0xc),CONCAT22(extraout_var,(short)*(char *)(param_1 + 3)),
               CONCAT22(extraout_var,*param_1),param_3,param_4);
  FUN_0046fa24(0x20);
  FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),0x88,
               CONCAT22(extraout_var_00,(short)*(char *)((int)param_1 + 5)) + 1);
  FUN_0046f917(&DAT_006e54e8,0xffffffff);
  FUN_0046fa24(0x20);
  uVar2 = extraout_var_01;
  if ((('\a' < *(char *)((int)param_1 + 5)) && (*(char *)((int)param_1 + 5) < '\v')) &&
     (*(char *)((int)param_1 + 7) == '\a')) {
    uVar1 = FUN_0047db81(param_3,0);
    FUN_0046f824(local_104,0,0x100);
    local_110[0] = &PTR_FUN_00666524;
    FUN_00465b21(&DAT_006e54e8,*(undefined4 *)(DAT_006e486c + 0xc),uVar1,
                 CONCAT22(extraout_var_02,param_1[1]));
    FUN_0046f917(&DAT_006e54e8,0xffffffff);
    FUN_0046f917(local_110,0xffffffff);
    uVar2 = extraout_var_03;
    if (local_108 != 0) {
      return;
    }
  }
  FUN_0047e457(*(undefined4 *)(param_2 + 0xc),CONCAT22(uVar2,(short)*(char *)((int)param_1 + 7)),
               CONCAT22(uVar2,param_1[1]),param_3,param_4);
  return;
}

