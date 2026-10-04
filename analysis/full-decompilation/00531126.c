
void FUN_00531126(void)

{
  int *piVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int iStackY_13c;
  
  FUN_00634c24();
  piVar1 = *(int **)(extraout_ECX[0x3a] + 0xc);
  uVar2 = (**(code **)(*piVar1 + 0x8c))(1);
  piVar6 = piVar1 + 0x13;
  *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
  FUN_005b86bd(piVar6);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar1 != (int *)0x0) {
    iVar4 = FUN_004102f3();
    if (iVar4 < *(int *)(unaff_EBP + 8)) {
      (**(code **)(*piVar1 + 0x94))();
      wsprintfA((LPSTR)(unaff_EBP + -0x128),(LPCSTR)extraout_ECX[0x5d],
                *(undefined4 *)(unaff_EBP + 8));
      FUN_005d4956(unaff_EBP + -0x128);
      iVar4 = *piVar1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      (**(code **)(iVar4 + 0x9c))(unaff_EBP + -0x1c);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      if (*(char *)(DAT_006e486c + 100) == '\x13') {
        *(int *)(unaff_EBP + 8) = *piVar6;
        piVar5 = (int *)FUN_005e40a5();
        iVar4 = (**(code **)(*piVar5 + 0x68))(*(undefined4 *)(unaff_EBP + 8),piVar1[0x14] - *piVar6)
        ;
        iStackY_13c = 9;
      }
      else {
        *(int *)(unaff_EBP + 8) = *piVar6;
        piVar5 = (int *)FUN_005e40a5();
        iVar4 = (**(code **)(*piVar5 + 0x68))(*(undefined4 *)(unaff_EBP + 8),piVar1[0x14] - *piVar6)
        ;
        iStackY_13c = 2;
      }
      piVar1[0x51] = iVar4 + 3;
      piVar1[0x52] = iStackY_13c;
      (**(code **)(*piVar1 + 0x168))();
    }
    else {
      (**(code **)(*piVar1 + 0x98))();
    }
  }
  cVar3 = (**(code **)(*piVar1 + 0x8c))(1);
  if (*(char *)(unaff_EBP + -0xd) == cVar3) {
    cVar3 = FUN_005d49dc(piVar6);
    if (cVar3 != '\0') goto LAB_0053126e;
  }
  piVar6 = (int *)(**(code **)(*extraout_ECX + 0x18))();
  (**(code **)(*piVar6 + 0x168))();
LAB_0053126e:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

