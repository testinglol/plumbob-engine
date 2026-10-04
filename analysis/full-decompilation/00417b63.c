
void __thiscall
FUN_00417b63(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
            char param_6)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar3 = 0xffffffcf;
  }
  else {
    uVar3 = 0;
  }
  FUN_004659fc(uVar3);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    return;
  }
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    iVar4 = -0x31;
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x20))();
    if (cVar1 != '\0') {
      iVar2 = FUN_00418326(param_1[6],param_3,param_4,0);
      if (iVar2 == 0) {
        iVar2 = FUN_004182c3(param_1 + 6,param_3);
      }
      else {
        if (*(int *)(iVar2 + 0x10) == param_2) {
          *(undefined4 *)(iVar2 + 0x10) = 0;
        }
        iVar4 = FUN_00417fc5(iVar2);
        if (iVar4 != 0) goto LAB_00417be2;
      }
      *(undefined2 *)(iVar2 + 4) = (undefined2)param_4;
      if (param_6 == '\0') {
        *(undefined2 *)(iVar2 + 6) = 0;
      }
      else {
        *(undefined2 *)(iVar2 + 6) = 0x10;
      }
      if ((char)param_1[10] != '\0') {
        *(byte *)(iVar2 + 6) = *(byte *)(iVar2 + 6) | 8;
      }
      *(int *)(iVar2 + 0x10) = param_2;
      iVar4 = (**(code **)*param_5)();
      if (iVar4 == 0) {
        *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
      }
      else {
        iVar4 = FUN_00416cf5();
        FUN_00416c4d(iVar4,param_5);
        *(int *)(iVar2 + 0xc) = iVar4;
        if (iVar4 == -1) {
          FUN_004659fc(0xffffffa0);
        }
      }
      *(undefined4 *)(iVar2 + 8) = 0xffffffff;
      return;
    }
    iVar4 = -0x2d;
  }
LAB_00417be2:
  FUN_004659fc(iVar4);
  return;
}

