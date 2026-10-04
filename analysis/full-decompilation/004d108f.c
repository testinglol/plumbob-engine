
undefined4 FUN_004d108f(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  char cVar3;
  undefined4 uVar4;
  size_t sVar5;
  int iVar6;
  int extraout_ECX;
  char *pcVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(extraout_ECX + 0x11d0);
  if (puVar1 != (undefined4 *)0x0) {
    for (pcVar7 = (char *)*puVar1; pcVar7 != (char *)puVar1[1]; pcVar7 = pcVar7 + 2) {
      if (*pcVar7 == *(char *)(unaff_EBP + 8)) {
        *(char *)(unaff_EBP + 8) = pcVar7[1];
        break;
      }
    }
  }
  iVar8 = (int)*(char *)(unaff_EBP + 8);
  if (iVar8 < 0x60) {
    if (iVar8 != 0x5f) {
      if (iVar8 == 0x2b) {
LAB_004d1106:
        FUN_004cef5b(1);
        goto LAB_004d143d;
      }
      if (iVar8 != 0x2d) {
        if (iVar8 == 0x31) {
          uVar4 = 1;
        }
        else if (iVar8 == 0x32) {
          uVar4 = 2;
        }
        else {
          if (iVar8 != 0x33) {
            if (iVar8 != 0x3d) goto LAB_004d1158;
            goto LAB_004d1106;
          }
          uVar4 = 3;
        }
        goto LAB_004d142c;
      }
    }
    FUN_004cef7c(1);
  }
  else if ((iVar8 == 0x60) || (iVar8 == 0x70)) {
LAB_004d141f:
    if (*(int *)(DAT_006f2a08 + 0x7c) == 0) {
      uVar4 = 0;
LAB_004d142c:
      FUN_0053bae0(uVar4);
    }
  }
  else if (iVar8 == 0x78) {
    if (DAT_006f2a08 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(DAT_006f2a08 + 0x88);
    }
    if (iVar8 != 0) {
      iVar6 = FUN_00401f6f();
      if (iVar6 == 0) {
        if (*(int *)(iVar8 + 0xe8) != 0) {
          FUN_005019eb();
        }
      }
      else {
        iVar6 = FUN_00401f6f();
        if ((iVar6 == 1) && (*(int *)(iVar8 + 0xe0) != 0)) {
          FUN_00507e55();
        }
      }
    }
  }
  else if (iVar8 == 0x7a) {
    if (DAT_006f2a08 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(DAT_006f2a08 + 0x88);
    }
    if (iVar8 != 0) {
      iVar6 = FUN_00401f6f();
      if (iVar6 == 0) {
        if (*(int *)(iVar8 + 0xe8) != 0) {
          FUN_005019bc();
        }
      }
      else {
        iVar6 = FUN_00401f6f();
        if ((iVar6 == 1) && (*(int *)(iVar8 + 0xe0) != 0)) {
          FUN_00507e26();
        }
      }
    }
  }
  else {
    if (iVar8 == 0x7e) goto LAB_004d141f;
LAB_004d1158:
    if ((DAT_006e54ac == (int *)0x0) ||
       (cVar3 = (**(code **)(*DAT_006e54ac + 0x50))(iVar8,*(undefined4 *)(extraout_ECX + 0x170)),
       cVar3 == '\0')) {
      if (iVar8 < 0x72) {
        if (iVar8 == 0x71) {
          (**(code **)(*(int *)(*(int *)(extraout_ECX + 0x108) + 0x48) + 0x28))();
        }
        else if (iVar8 == 0x2c) {
LAB_004d11a1:
          FUN_004cef2b(1);
        }
        else {
          if (iVar8 != 0x2e) {
            if (iVar8 == 0x3c) goto LAB_004d11a1;
            if (iVar8 != 0x3e) goto LAB_004d11db;
          }
          FUN_004cef47(1);
        }
      }
      else if (iVar8 == 0x73) {
        DAT_006f0138 = DAT_006f0138 == '\0';
        (**(code **)(**(int **)(DAT_006e486c + 4) + 0x48))();
      }
      else if (iVar8 == 0x74) {
        cVar3 = FUN_004d381d();
        FUN_004d3834('\x01' - (cVar3 != '\0'));
      }
      else {
        if (iVar8 != 0x76) {
LAB_004d11db:
          uVar4 = FUN_005dd715(*(undefined4 *)(unaff_EBP + 8));
          goto LAB_004d143f;
        }
        FUN_005d48d9();
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_005d4956(s_Build_Version_006c7c1c);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0046fca5();
        *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_0066643c;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        uVar4 = FUN_0041532c(9,unaff_EBP + -0x90,0);
        cVar3 = FUN_004fff98(0x9a,uVar4);
        if (cVar3 != '\0') {
          iVar8 = FUN_004705f2(0xb,0xffffffff);
          if (iVar8 != 0) {
            pcVar7 = (char *)FUN_004705f2(0xb,0xffffffff);
            sVar5 = _strlen(pcVar7);
            FUN_00412d8a(pcVar7,pcVar7 + sVar5);
            sVar5 = _strlen(&DAT_006c08dc);
            FUN_00412d8a(&DAT_006c08dc,&DAT_006c08dc + sVar5);
          }
          iVar8 = FUN_004705f2(0xc,0xffffffff);
          if (iVar8 != 0) {
            uVar4 = FUN_004705f2(0xc,0xffffffff);
            FUN_005d4bbf(uVar4);
          }
        }
        puVar2 = PTR_s_Sep_25_2003__14_23_46_006c7b6c;
        sVar5 = _strlen(PTR_s_Sep_25_2003__14_23_46_006c7b6c);
        FUN_00412d8a(puVar2,puVar2 + sVar5);
        (**(code **)(*(int *)(*(int *)(extraout_ECX + 0x108) + 0x48) + 0x2c))
                  (unaff_EBP + -0x18,unaff_EBP + -0x24,0,0);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00470467();
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
    }
  }
LAB_004d143d:
  uVar4 = 1;
LAB_004d143f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

