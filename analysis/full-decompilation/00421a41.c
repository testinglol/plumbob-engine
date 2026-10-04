
undefined4 __fastcall FUN_00421a41(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int local_10;
  int local_c;
  int local_8;
  
  if ((param_1[0x6b] == 0) || ((short)param_1[0x6c] == 0)) {
    uVar2 = 0;
  }
  else {
    FUN_00421e75();
    local_10 = param_1[0x6d];
    piVar1 = (int *)param_1[0x6b];
    local_c = param_1[0x6e];
    local_8 = param_1[0x6f];
    (**(code **)(*param_1 + 0x50))(1);
    piVar3 = param_1;
    piVar4 = (int *)param_1[100];
    if ((int *)param_1[100] != (int *)0x0) goto LAB_00421aa8;
    while (piVar4 = piVar3, piVar3 != (int *)0x0) {
LAB_00421aa8:
      FUN_004341a6(0);
      FUN_0044582f((int)*(short *)(piVar4[0x6b] + 0xf0),1,1);
      FUN_00432189(*(uint *)(piVar4[0x6b] + 0x114) & 0x1e);
      piVar4[0x6b] = 0;
      piVar3 = (int *)piVar4[99];
    }
    uVar2 = FUN_00407498((int)(short)param_1[0x71]);
    (**(code **)(*piVar1 + 100))(&local_10,local_8,uVar2,(int)*(short *)((int)param_1 + 0x1c6));
    uVar2 = 1;
  }
  return uVar2;
}

