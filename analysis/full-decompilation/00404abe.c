
void FUN_00404abe(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  iVar1 = 0xc;
  if (param_2 == 0) {
LAB_00404acc:
    param_2 = iVar1;
    uVar3 = 0x61;
  }
  else {
    if (param_2 != 0xc) {
      iVar1 = param_2;
      if (param_2 < 0xd) goto LAB_00404acc;
      param_2 = param_2 + -0xc;
    }
    uVar3 = 0x70;
  }
  iVar1 = 0xc;
  if (param_3 == 0) {
LAB_00404af6:
    param_3 = iVar1;
    uVar2 = 0x61;
  }
  else {
    if (param_3 != 0xc) {
      iVar1 = param_3;
      if (param_3 < 0xd) goto LAB_00404af6;
      param_3 = param_3 + -0xc;
    }
    uVar2 = 0x70;
  }
  FUN_00635858(param_1,s__d_c__d_c_006c0e14,param_2,uVar3,param_3,uVar2);
  return;
}

