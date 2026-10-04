
void __fastcall FUN_00487f4b(int *param_1)

{
  int *piVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  
  if (param_1[0xf] != 0) {
    piVar1 = *(int **)(param_1[0xf] + 0x1ac);
    if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x70))(), cVar2 != '\0')) {
      if ((param_1[0xf] != 0) && (cVar2 = FUN_00432644(), cVar2 != '\0')) {
        (**(code **)(*(int *)param_1[0xf] + 0x50))(1);
      }
      if (*(char *)((int)param_1 + 0x75) == '\0') {
        sVar3 = FUN_00432249();
        iVar4 = (int)sVar3;
        if (param_1[0xc] != 0) {
          *(int *)(param_1[0xc] + 0x24) = iVar4;
        }
        if ((char)param_1[0x1e] == '\0') {
          iVar4 = 0;
        }
        else if (*(char *)((int)param_1 + 0x77) != '\0') {
          iVar4 = __ftol();
        }
        param_1[8] = param_1[8] - iVar4;
        FUN_00492bc4();
        if (iVar4 == 0) {
          FUN_00492cca();
        }
        else {
          FUN_00492c99();
        }
      }
      else {
        (**(code **)(*param_1 + 0x60))();
      }
      (**(code **)(*param_1 + 0x18))();
      (**(code **)(*param_1 + 0x60))();
      return;
    }
    FUN_00492c37();
  }
  return;
}

