
void FUN_004e5493(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  cVar1 = FUN_004e5685(param_3,param_4);
  if (cVar1 != '\0') {
    iVar4 = (param_4[2] - *param_4) / 2;
    iVar2 = ((param_4[3] - param_4[1]) * 3) / 4;
    iVar3 = iVar2 + 0xe;
    if (((param_1 == 2) || (param_1 == 0xd)) || (param_1 == 0xe)) {
      iVar3 = iVar2 + -0x10;
    }
    else if (param_1 == 0xc) {
      iVar3 = iVar2 + -2;
    }
    uVar7 = 0;
    uVar6 = 6;
    uVar5 = 2;
    FUN_00540a5b(iVar4,iVar3,2,param_1,param_2,6,0);
    FUN_00540c42(iVar4,iVar3,uVar5,param_1,param_2,uVar6,uVar7);
    FUN_004e586d(param_3);
  }
  return;
}

