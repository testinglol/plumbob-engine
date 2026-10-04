
void FUN_0047f70e(short *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined2 extraout_var;
  int iVar2;
  undefined *puVar3;
  undefined1 local_104 [256];
  
  iVar2 = 0;
  FUN_0046f824(local_104,0,0x100);
  FUN_0046fa24(0x28);
  sVar1 = param_1[1];
  if (sVar1 == 0) {
    FUN_0046f847(&DAT_006c54e4,0xffffffff);
    FUN_0047e457(*(undefined4 *)(param_2 + 0xc),9,CONCAT22(extraout_var,*param_1),param_3,param_4);
LAB_0047f7b2:
    if (iVar2 == 0) goto LAB_0047f7cf;
    puVar3 = &DAT_006c518c;
  }
  else {
    if (sVar1 == 1) {
      iVar2 = FUN_00401f6f();
      goto LAB_0047f7b2;
    }
    if (sVar1 == 2) {
      FUN_0046f847(s_global__006c54e8,0xffffffff);
      iVar2 = FUN_00401f73();
      goto LAB_0047f7b2;
    }
    puVar3 = &DAT_006c54f4;
  }
  FUN_0046f847(puVar3,0xffffffff);
  FUN_0046fa40((int)*param_1);
LAB_0047f7cf:
  if ((~*(byte *)(param_1 + 2) & 1) == 0) {
    FUN_0046f847(s___no_failure_trees_006c54d0,0xffffffff);
  }
  FUN_0046fa24(0x29);
  return;
}

