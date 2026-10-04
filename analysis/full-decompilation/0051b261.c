
void __fastcall FUN_0051b261(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 unaff_retaddr;
  
  cVar2 = (**(code **)(*param_1 + 0x8c))(1);
  if (cVar2 != '\0') {
    cVar2 = FUN_004cff80();
    if (cVar2 != '\0') {
      iVar1 = param_1[0x3f];
      if (iVar1 == 1) {
        (**(code **)(*(int *)param_1[0x40] + 0x16c))();
        piVar3 = (int *)param_1[0x41];
      }
      else if (iVar1 == 2) {
        piVar3 = (int *)param_1[0x42];
      }
      else if (iVar1 == 3) {
        (**(code **)(*(int *)param_1[0x44] + 0x16c))();
        (**(code **)(*(int *)param_1[0x49] + 0x16c))();
        (**(code **)(*(int *)param_1[0x45] + 0x16c))();
        (**(code **)(*(int *)param_1[0x46] + 0x16c))();
        piVar3 = (int *)param_1[0x47];
      }
      else if (iVar1 == 4) {
        piVar3 = (int *)param_1[0x48];
      }
      else if (iVar1 == 5) {
        piVar3 = (int *)param_1[0x43];
      }
      else if (iVar1 == 6) {
        piVar3 = (int *)param_1[0xce];
      }
      else {
        if (iVar1 != 7) goto LAB_0051b32c;
        piVar3 = (int *)param_1[0x104];
      }
      (**(code **)(*piVar3 + 0x16c))();
    }
  }
LAB_0051b32c:
  FUN_005dcd25(unaff_retaddr);
  return;
}

