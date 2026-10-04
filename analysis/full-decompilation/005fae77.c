
undefined1 __thiscall
FUN_005fae77(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined1 uVar4;
  
  cVar2 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar2 == '\0') {
    uVar4 = 1;
  }
  else if ((char)param_1[0xb] == '\0') {
    uVar4 = (**(code **)(*param_1 + 0xd0))(param_2,param_3,param_4);
  }
  else {
    piVar1 = (int *)param_1[1];
    if (piVar1 == (int *)0x0) {
      uVar4 = 0;
    }
    else {
      (**(code **)(*piVar1 + 0x4c))(piVar1,param_2,param_3,param_4,0);
      iVar3 = (**(code **)(*(int *)param_1[1] + 0x50))((int *)param_1[1],param_5,param_6,param_7,1);
      uVar4 = iVar3 == 0;
    }
  }
  return uVar4;
}

