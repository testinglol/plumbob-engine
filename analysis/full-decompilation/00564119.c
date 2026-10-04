
void FUN_00564119(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  void *pvVar8;
  int *piVar9;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar10;
  int *piVar11;
  
  FUN_00634c24();
  iVar6 = *(int *)(unaff_EBP + 8);
  piVar10 = (int *)0x0;
  if ((((iVar6 < 0) || (3 < iVar6)) || (extraout_ECX[iVar6 + 0x42] == 0)) ||
     ((char)extraout_ECX[0x56] != '\0')) goto LAB_00564362;
  *(undefined1 *)(extraout_ECX + 0x56) = 1;
  if (iVar6 == 0) {
    if (DAT_006f5c08 == '\0') {
      DAT_006f5c08 = '\x01';
      pvVar8 = operator_new(0x1bc);
      *(void **)(unaff_EBP + 8) = pvVar8;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar8 != (void *)0x0) {
        piVar10 = (int *)FUN_0054866a();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (piVar10 != (int *)0x0) {
        (**(code **)(*extraout_ECX + 0x98))();
        iVar6 = extraout_ECX[0x1f];
        iVar1 = extraout_ECX[0x20];
        iVar2 = extraout_ECX[0x21];
        *(int *)(unaff_EBP + -0x10) = extraout_ECX[0x22];
        (**(code **)(*piVar10 + 0x60))(iVar6,iVar1,iVar2,*(undefined4 *)(unaff_EBP + -0x10));
        piVar10[0x57] = (int)extraout_ECX;
        cVar4 = (**(code **)(*piVar10 + 0xc))();
        if (cVar4 != '\0') {
          piVar9 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
          piVar3 = DAT_006fe8bc;
          piVar11 = piVar10;
          uVar7 = (**(code **)(*piVar9 + 8))(piVar10);
          (**(code **)(*piVar3 + 0x18))(uVar7);
          FUN_005daa44(uVar7,piVar11);
        }
        FUN_005da4c7(piVar10);
        (**(code **)(*extraout_ECX + 0x94))();
        FUN_00436e16();
        FUN_005db1e2();
      }
      DAT_006f5c08 = '\0';
    }
  }
  else if (iVar6 == 1) {
    if ((extraout_ECX[0x4c] != 0) && (iVar6 = FUN_0054493f(), iVar6 != -1)) {
      uVar7 = FUN_0054493f();
      puVar5 = (undefined4 *)extraout_ECX[0x51];
      *(undefined4 *)(unaff_EBP + -0x1c) = 3;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x20;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar7;
      if ((puVar5 != (undefined4 *)0x0) && (cVar4 = FUN_005da398(puVar5), cVar4 != '\0')) {
        (**(code **)*puVar5)(unaff_EBP + -0x1c);
      }
LAB_00564181:
      FUN_005dac30(0x10,extraout_ECX,0);
    }
  }
  else if (iVar6 == 2) {
    if ((extraout_ECX[0x4c] != 0) &&
       (puVar5 = (undefined4 *)FUN_005448ab(), puVar5 != (undefined4 *)0x0)) {
      wsprintfA((LPSTR)(unaff_EBP + -300),(LPCSTR)extraout_ECX[0x49],*puVar5);
      FUN_005d4956(unaff_EBP + -300);
      piVar10 = (int *)(DAT_006f2a08 + 0x48);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      iVar6 = (**(code **)(*piVar10 + 0x2c))(unaff_EBP + -0x28,extraout_ECX + 0x46,1,0);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      if (iVar6 == 3) {
        FUN_0054457c();
      }
    }
  }
  else if (iVar6 == 3) goto LAB_00564181;
  *(undefined1 *)(extraout_ECX + 0x56) = 0;
LAB_00564362:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

