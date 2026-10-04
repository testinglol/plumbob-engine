
undefined4 __fastcall FUN_0048c284(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (((char)param_1[8] == '\0') || (piVar1 = DAT_006e5790, *param_1 == 0)) {
    return 0;
  }
  do {
    if (piVar1 == DAT_006e5794) {
      iVar2 = 0;
LAB_0048c2b4:
      return *(undefined4 *)(iVar2 + 0xc);
    }
    if (*(int *)(*piVar1 + 8) == *param_1) {
      iVar2 = *piVar1;
      goto LAB_0048c2b4;
    }
    piVar1 = piVar1 + 1;
  } while( true );
}

