
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_00491b2b(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int extraout_ECX;
  int unaff_EBP;
  char *pcVar5;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  cVar1 = *(char *)(extraout_ECX + 0x2c);
  if ((cVar1 == '\0') && (*(int *)(extraout_ECX + 0x38) == 0)) {
    if (*(int *)(extraout_ECX + 0x30) == 0) {
      FUN_00492d46(0);
    }
    else {
      FUN_005d48d9();
      piVar4 = DAT_006fe8bc;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      piVar4 = (int *)(**(code **)(*piVar4 + 4))();
      (**(code **)(*piVar4 + 0x7c))
                (*(int *)(extraout_ECX + 0x30),*(int *)(extraout_ECX + 0x30) >> 0x1f,
                 unaff_EBP + -0x24);
      FUN_00492d46(*(undefined4 *)(unaff_EBP + -0x24));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    *(undefined4 *)(extraout_ECX + 0x3c) = *(undefined4 *)(extraout_ECX + 0x38);
    goto LAB_00491c5e;
  }
  iVar2 = *(int *)(extraout_ECX + 0x38);
  if (*(int *)(extraout_ECX + 0x3c) == iVar2) {
    *(bool *)(unaff_EBP + -0xd) = cVar1 == '\0';
    goto LAB_00491c5e;
  }
  *(int *)(extraout_ECX + 0x3c) = iVar2;
  *(bool *)(unaff_EBP + -0xd) = cVar1 == '\0';
  switch(iVar2) {
  case 1:
    pcVar5 = (char *)*DAT_006e57c4;
    break;
  case 2:
    pcVar5 = (char *)DAT_006e57c4[3];
    break;
  case 3:
    pcVar5 = (char *)DAT_006e57c4[6];
    break;
  case 4:
    pcVar5 = (char *)DAT_006e57c4[9];
    break;
  case 5:
    pcVar5 = (char *)DAT_006e57c4[0xc];
    break;
  case 6:
    FUN_005d48d9();
    puVar3 = DAT_006e57c4;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00412d8a(puVar3[0xf],puVar3[0x10]);
    FUN_00492d46(*(undefined4 *)(unaff_EBP + -0x24));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    goto LAB_00491c5e;
  case 7:
    pcVar5 = s_Area_too_large_006c6064;
    break;
  case 8:
    FUN_00492d46(DAT_006e57c4[0x12]);
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
    goto LAB_00491c5e;
  default:
    pcVar5 = (char *)0x0;
  }
  FUN_00492d46(pcVar5);
LAB_00491c5e:
  piVar4 = *(int **)(extraout_ECX + 0x48);
  *(int *)(extraout_ECX + 0x40) = DAT_006e5490 + 500;
  if (piVar4 != (int *)0x0) {
    if (*(char *)(unaff_EBP + -0xd) == '\0') {
      (**(code **)(*piVar4 + 0x50))(1);
    }
    else {
      FUN_00422055((int)*(char *)(extraout_ECX + 0x34),(int)*(char *)(extraout_ECX + 0x35));
      FUN_00490d54(piVar4,unaff_EBP + -0x18);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

