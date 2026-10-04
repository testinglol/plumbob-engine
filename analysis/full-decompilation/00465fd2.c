
int FUN_00465fd2(int param_1,int param_2,code *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  if (param_2 == 0) {
    uVar1 = FUN_004cba72();
    FUN_00401f73();
    iVar5 = FUN_0041ffd9(uVar1);
    if (iVar5 == 0) {
      if (param_1 != 0) {
        FUN_005c3314();
        FUN_006321f0(param_1);
      }
      FUN_004659fc(0xffffff38);
    }
    else {
      uVar2 = FUN_00420048(iVar5);
      uVar3 = FUN_004cba72();
      FUN_00401f73();
      FUN_006331bc(uVar2,uVar3);
      if (param_3 != (code *)0x0) {
        (*param_3)(uVar2,uVar1);
      }
      FUN_0042004f(iVar5);
      piVar4 = operator_new(8);
      *piVar4 = param_1;
      piVar4[1] = iVar5;
      FUN_00466617(piVar4);
      FUN_004659fc(0);
    }
  }
  else {
    FUN_004659fc(param_2);
    if (param_1 != 0) {
      FUN_005c3314();
      FUN_006321f0(param_1);
    }
  }
  return iVar5;
}

