
void __thiscall FUN_004d29e6(int *param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  piVar1 = param_1 + 0x45f;
  uVar5 = 0xffffffff;
  if (param_1[0x460] - *piVar1 >> 2 != 0) {
    piVar3 = (int *)*piVar1;
    do {
      uVar5 = uVar4;
      if ((int *)*piVar3 == param_2) break;
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
      uVar5 = 0xffffffff;
    } while (uVar4 < (uint)(param_1[0x460] - *piVar1 >> 2));
  }
  cVar2 = (**(code **)(*param_1 + 0x38))(param_2);
  if (cVar2 != '\0') {
    FUN_005ddfdc(0);
    (**(code **)(*param_2 + 0x98))();
  }
  FUN_0042ec52(*piVar1 + uVar5 * 4);
  FUN_004cb0b0(0);
  FUN_004d40e1(&param_2);
  FUN_005db0b7();
  return;
}

