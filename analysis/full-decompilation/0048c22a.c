
undefined4 __fastcall FUN_0048c22a(int *param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  
  if (((char)param_1[8] == '\0') || (sVar1 = FUN_0048c2bc(), sVar1 == 0)) {
    return 0;
  }
  piVar2 = (int *)FUN_0048c284();
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x6c))(1);
    piVar2 = DAT_006e5790;
    if (*param_1 != 0) {
      for (; piVar2 != DAT_006e5794; piVar2 = piVar2 + 1) {
        if (*(int *)(*piVar2 + 8) == *param_1) {
          iVar3 = *piVar2;
          goto LAB_0048c27c;
        }
      }
      iVar3 = 0;
LAB_0048c27c:
      *(undefined1 *)(iVar3 + 0x10) = 1;
    }
  }
  return 1;
}

