
undefined4 __fastcall FUN_005ec29f(int *param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  
  cVar3 = (**(code **)(*(int *)param_1[0x12] + 0x58))(param_1 + 2);
  if (cVar3 == '\0') {
LAB_005ec2cd:
    uVar4 = 0;
  }
  else {
    iVar1 = param_1[2];
    if ((iVar1 == 3) || (iVar1 == 2)) {
      cVar3 = (**(code **)(*param_1 + 0x124))();
      if (cVar3 == '\0') goto LAB_005ec2cd;
    }
    if (DAT_006fea78 == '\0') {
      _memset(&DAT_006fea58,0,0x20);
      DAT_006fea58 = 0x20;
    }
    piVar2 = *(int **)(param_1[0x12] + 8);
    if (piVar2 == (int *)0x0) {
      piVar2 = *(int **)(param_1[0x12] + 4);
      (**(code **)(*piVar2 + 0x54))(piVar2,&DAT_006fea58);
    }
    else {
      (**(code **)(*piVar2 + 0x54))(piVar2,&DAT_006fea58);
    }
    DAT_006fea78 = '\x01';
    uVar4 = 1;
  }
  return uVar4;
}

