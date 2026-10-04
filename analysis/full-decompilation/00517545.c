
void __thiscall FUN_00517545(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  
  FUN_004e609e();
  cVar2 = FUN_004e6133();
  iVar1 = *(int *)(param_1 + 0xdc);
  if (iVar1 != param_2) {
    if (iVar1 == 0) {
      if (param_1 != 0) {
        FUN_005da644(param_1,0x1b,0,0xffffffff,0);
      }
    }
    else {
      if (iVar1 == 1) {
        if (*(int **)(param_1 + 0x188) != (int *)0x0) {
          iVar1 = **(int **)(param_1 + 0x188);
          if (cVar2 == '\0') {
            (**(code **)(iVar1 + 0x98))();
          }
          else {
            (**(code **)(iVar1 + 0xa8))(0,0,0);
          }
        }
      }
      else if (iVar1 == 2) {
        if (*(int **)(param_1 + 0x18c) != (int *)0x0) {
          iVar1 = **(int **)(param_1 + 0x18c);
          if (cVar2 == '\0') {
            (**(code **)(iVar1 + 0x98))();
          }
          else {
            (**(code **)(iVar1 + 0xa8))(0,0,0);
          }
        }
      }
      else {
        if (iVar1 != 3) goto LAB_00517620;
        if (*(int **)(param_1 + 400) != (int *)0x0) {
          iVar1 = **(int **)(param_1 + 400);
          if (cVar2 == '\0') {
            (**(code **)(iVar1 + 0x98))();
          }
          else {
            (**(code **)(iVar1 + 0xa8))(0,0,0);
          }
        }
      }
      FUN_005e46f0(0);
    }
LAB_00517620:
    if (*(char *)(*(int *)(param_1 + 0x194) + 0xe0) != '\0') {
      FUN_0050fc0a(1);
    }
  }
  *(int *)(param_1 + 0xdc) = param_2;
  if (*(int *)(param_1 + 400) != 0) {
    cVar3 = FUN_004074bc();
    if (cVar3 == '\x01') {
      (**(code **)(**(int **)(param_1 + 0x164) + 0x94))();
LAB_00517738:
      (**(code **)(**(int **)(param_1 + 0x158) + 0x90))(2,1);
      (**(code **)(**(int **)(param_1 + 0x148) + 0x90))(2,1);
      (**(code **)(**(int **)(param_1 + 0x148) + 0x94))();
      (**(code **)(**(int **)(param_1 + 0x158) + 0x94))();
    }
    else {
      cVar3 = FUN_004074f7();
      if (((cVar3 == '\x01') || (cVar3 = FUN_0040750e(), cVar3 == '\x01')) ||
         (cVar3 = FUN_0042886f(), cVar3 == '\x01')) {
        (**(code **)(**(int **)(param_1 + 0x164) + 0x98))();
        (**(code **)(**(int **)(param_1 + 0x158) + 0x90))(2,0);
        (**(code **)(**(int **)(param_1 + 0x148) + 0x90))(2,0);
        (**(code **)(**(int **)(param_1 + 0x148) + 0x98))();
        (**(code **)(**(int **)(param_1 + 0x158) + 0x98))();
        (**(code **)(**(int **)(param_1 + 0x164) + 0x98))();
      }
      else {
        cVar3 = FUN_00407525();
        if ((cVar3 == '\x01') || (cVar3 = FUN_004074d9(), cVar3 == '\x01')) {
          (**(code **)(**(int **)(param_1 + 0x164) + 0x98))();
          goto LAB_00517738;
        }
      }
    }
  }
  if (cVar2 != '\0') {
    return;
  }
  iVar1 = *(int *)(param_1 + 0xdc);
  if (iVar1 == 1) {
    if (*(int **)(param_1 + 0x188) == (int *)0x0) goto LAB_0051794d;
    (**(code **)(**(int **)(param_1 + 0x188) + 0x94))();
    (**(code **)(**(int **)(param_1 + 0x110) + 0x98))();
    piVar4 = *(int **)(param_1 + 0xf8);
  }
  else {
    if (iVar1 == 2) {
      if (*(int **)(param_1 + 0x18c) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 0x18c) + 0x94))();
      }
      goto LAB_0051794d;
    }
    if ((iVar1 != 3) || (*(int **)(param_1 + 400) == (int *)0x0)) goto LAB_0051794d;
    (**(code **)(**(int **)(param_1 + 400) + 0x94))();
    cVar2 = FUN_004074bc();
    if (cVar2 == '\x01') {
      (**(code **)(**(int **)(param_1 + 0x148) + 0x94))();
      (**(code **)(**(int **)(param_1 + 0x158) + 0x94))();
      (**(code **)(**(int **)(param_1 + 0x164) + 0x94))();
      (**(code **)(**(int **)(param_1 + 0x158) + 0x90))(2,1);
      (**(code **)(**(int **)(param_1 + 0x148) + 0x90))(2,1);
      goto LAB_0051794d;
    }
    cVar2 = FUN_004074f7();
    if (((cVar2 == '\x01') || (cVar2 = FUN_0040750e(), cVar2 == '\x01')) ||
       (cVar2 = FUN_0042886f(), cVar2 == '\x01')) {
      (**(code **)(**(int **)(param_1 + 0x158) + 0x90))(2,0);
      (**(code **)(**(int **)(param_1 + 0x148) + 0x90))(2,0);
      (**(code **)(**(int **)(param_1 + 0x148) + 0x98))();
      (**(code **)(**(int **)(param_1 + 0x158) + 0x98))();
    }
    else {
      cVar2 = FUN_00407525();
      if ((cVar2 != '\x01') && (cVar2 = FUN_004074d9(), cVar2 != '\x01')) goto LAB_0051794d;
      (**(code **)(**(int **)(param_1 + 0x158) + 0x90))(2,1);
      (**(code **)(**(int **)(param_1 + 0x148) + 0x90))(2,1);
      (**(code **)(**(int **)(param_1 + 0x148) + 0x94))();
      (**(code **)(**(int **)(param_1 + 0x158) + 0x94))();
    }
    piVar4 = *(int **)(param_1 + 0x164);
  }
  (**(code **)(*piVar4 + 0x98))();
LAB_0051794d:
  (**(code **)(**(int **)(param_1 + 0x158) + 0x90))(2,1);
  (**(code **)(**(int **)(param_1 + 0x148) + 0x90))(2,1);
  return;
}

