
void __thiscall
FUN_00406edb(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  
  FUN_004659fc(0);
  iVar4 = (**(code **)(*param_1 + 0x44))(param_3,param_4,param_6,0);
  if (iVar4 != 0) {
    if (iVar4 == param_2) {
      (**(code **)(*param_1 + 100))(iVar4);
      iVar4 = (**(code **)(*param_1 + 0x44))(param_3,param_4,param_6,0);
    }
    (**(code **)(*param_1 + 0x80))(iVar4);
    iVar4 = FUN_00401f6f();
    if (iVar4 != 0) {
      return;
    }
  }
  FUN_004659fc(0xffffffa2);
  iVar4 = 0;
  do {
    if ((int *)param_1[iVar4 * 5 + 3] == (int *)0x0) {
      return;
    }
    bVar2 = false;
    iVar1 = iVar4 + 1;
    for (piVar6 = (int *)param_1[iVar4 * 5 + 4]; piVar6 != (int *)param_1[iVar1 * 5];
        piVar6 = piVar6 + 1) {
      if (*piVar6 == param_3) {
        bVar2 = true;
        break;
      }
    }
    if ((short)param_1[iVar4 * 5 + 7] == 0) {
      if (!bVar2) goto LAB_00406f9e;
LAB_00406fa9:
      cVar3 = (**(code **)(*(int *)param_1[iVar4 * 5 + 3] + 0x20))();
      if (cVar3 != '\0') {
        (**(code **)(*(int *)param_1[iVar4 * 5 + 3] + 0x78))
                  (param_2,param_3,param_4,param_5,param_6,param_7);
        uVar5 = FUN_00401f6f();
        FUN_004659fc(uVar5);
        return;
      }
    }
    else {
      if (!bVar2) goto LAB_00406fa9;
LAB_00406f9e:
      FUN_004659fc(0xffffffa4);
    }
    iVar4 = iVar1;
    if (7 < iVar1) {
      return;
    }
  } while( true );
}

