
uint __thiscall FUN_005dcbd1(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  int local_8;
  
  local_8 = 0;
  FUN_00576b0a(*(undefined4 *)param_1[0xe],(undefined4 *)param_1[0xe],&local_8);
  piVar2 = param_2;
  while (local_8 != 0) {
    param_2 = *(int **)param_1[0xe];
    while( true ) {
      if (param_2 == (int *)param_1[0xe]) goto LAB_005dcc64;
      piVar1 = (int *)param_2[2];
      cVar3 = (**(code **)(*piVar1 + 0x8c))(1);
      if (((cVar3 != '\0') && (cVar3 = (**(code **)(*piVar1 + 0x8c))(2), cVar3 != '\0')) &&
         (cVar3 = (**(code **)(*piVar1 + 0x70))(piVar2[1],piVar2[2]), cVar3 != '\0')) break;
      param_2 = (int *)*param_2;
    }
    local_8 = 0;
    FUN_00576b0a(*(undefined4 *)piVar1[0xe],(undefined4 *)piVar1[0xe],&local_8);
    param_1 = piVar1;
  }
LAB_005dcc64:
  uVar4 = (**(code **)(*param_1 + 0x8c))(1);
  if (((char)uVar4 != '\0') && (uVar4 = (**(code **)(*param_1 + 0x8c))(2), (char)uVar4 != '\0')) {
    if ((*piVar2 == 7) || (*piVar2 == 8)) {
      (**(code **)(*param_1 + 0x44))();
      FUN_00436e16();
    }
    FUN_005d99a9(param_1,piVar2);
    param_2 = (int *)0x0;
    local_8 = 0;
    FUN_00436feb(&param_2,&local_8);
    piVar2[1] = piVar2[1] - (int)param_2;
    piVar2[2] = piVar2[2] - local_8;
    if (*piVar2 == 0xd) {
      FUN_005ddddb();
    }
    else if (*piVar2 == 0xf) {
      FUN_005e749a(0);
      FUN_005e73da();
      FUN_005e743b();
    }
    uVar4 = (**(code **)*param_1)(piVar2);
    return uVar4;
  }
  return uVar4 & 0xffffff00;
}

