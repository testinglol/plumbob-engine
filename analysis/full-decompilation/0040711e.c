
undefined4 __thiscall FUN_0040711e(int *param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int local_8;
  
  local_8 = 0;
  do {
    if (param_1[3] == 0) {
      return 0;
    }
    piVar4 = (int *)param_1[4];
    piVar1 = (int *)param_1[5];
    bVar2 = false;
    if (piVar4 == piVar1) {
LAB_00407159:
      if ((short)param_1[7] != 0) {
LAB_00407160:
        cVar3 = (**(code **)(*(int *)param_1[3] + 0x20))();
        if (cVar3 != '\0') {
          return 1;
        }
      }
    }
    else {
      do {
        if (*piVar4 == param_2) {
          bVar2 = true;
        }
        piVar4 = piVar4 + 1;
      } while (piVar4 != piVar1);
      if (!bVar2) goto LAB_00407159;
      if ((short)param_1[7] == 0) goto LAB_00407160;
    }
    local_8 = local_8 + 1;
    param_1 = param_1 + 5;
    if (7 < local_8) {
      return 0;
    }
  } while( true );
}

