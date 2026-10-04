
void FUN_00491f06(void)

{
  char cVar1;
  undefined1 uVar2;
  size_t sVar3;
  int iVar4;
  int extraout_ECX;
  char cVar5;
  int unaff_EBP;
  char *pcVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(extraout_ECX + 0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(extraout_ECX + 0x54);
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  sVar3 = _strlen(s_altitude_006c4f68);
  FUN_00401a3c(s_altitude_006c4f68,s_altitude_006c4f68 + sVar3);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0043162f(unaff_EBP + -0x34);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00401729();
  cVar1 = *(char *)(extraout_ECX + 0x5d);
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(extraout_ECX + 0x30);
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  if (cVar1 == '\0') {
    uVar2 = FUN_00491113(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x1c));
    *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    do {
      if (*(char *)(unaff_EBP + -0xd) == '\0') goto LAB_00492146;
      *(undefined1 *)(unaff_EBP + -0x12) = 0;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      cVar1 = FUN_0046f59a(4);
      pcVar6 = *(char **)(unaff_EBP + 8);
      *(char *)(unaff_EBP + -0x14) = cVar1 + *pcVar6;
      cVar1 = FUN_0046f59a(4);
      iVar4 = DAT_006e54d8;
      cVar1 = cVar1 + pcVar6[1];
      *(char *)(unaff_EBP + -0x13) = cVar1;
      if (((((int)*(char *)(unaff_EBP + -0x14) < *(int *)(iVar4 + 0x70) + 1) ||
           (*(int *)(iVar4 + 0x74) + -1 < (int)*(char *)(unaff_EBP + -0x14))) ||
          ((int)cVar1 < *(int *)(iVar4 + 0x78) + 1)) || (*(int *)(iVar4 + 0x7c) + -1 < (int)cVar1))
      {
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      else {
        *(undefined1 **)(unaff_EBP + -0x18) = &DAT_006e57b4;
        do {
          *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(unaff_EBP + -0x12);
          *(undefined1 *)(unaff_EBP + -4) = 3;
          cVar1 = **(char **)(unaff_EBP + -0x18) + *(char *)(unaff_EBP + -0x14);
          cVar5 = (*(char **)(unaff_EBP + -0x18))[1] + *(char *)(unaff_EBP + -0x13);
          *(char *)(unaff_EBP + -0x20) = cVar1;
          *(char *)(unaff_EBP + -0x1f) = cVar5;
          if (((*(int *)(iVar4 + 0x70) + 1 <= (int)cVar1) &&
              ((int)cVar1 <= *(int *)(iVar4 + 0x74) + -1)) &&
             ((*(int *)(iVar4 + 0x78) + 1 <= (int)cVar5 &&
              (((int)cVar5 <= *(int *)(iVar4 + 0x7c) + -1 &&
               (cVar1 = FUN_00490f92(unaff_EBP + -0x20,*(undefined4 *)(unaff_EBP + -0x1c)),
               iVar4 = DAT_006e54d8, cVar1 == '\0')))))) {
            *(undefined1 *)(unaff_EBP + -4) = 2;
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
            break;
          }
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 3;
          *(undefined1 *)(unaff_EBP + -4) = 2;
        } while (*(int *)(unaff_EBP + -0x18) < 0x6e57c0);
        if ((*(char *)(unaff_EBP + -0xd) == '\0') ||
           (cVar1 = FUN_00490f92(unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + -0x1c)),
           cVar1 == '\0')) {
LAB_0049209c:
          *(undefined1 *)(unaff_EBP + -0xd) = 0;
        }
        else {
          cVar1 = FUN_00490f92(unaff_EBP + -0x14,*(undefined4 *)(unaff_EBP + -0x1c));
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
          if (cVar1 == '\0') goto LAB_0049209c;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
    } while (*(int *)(unaff_EBP + -0x24) < 7);
  }
  if (*(char *)(unaff_EBP + -0xd) != '\0') {
    iVar4 = *(int *)(extraout_ECX + 0x30) - *(int *)(unaff_EBP + -0x28);
    *(int *)(unaff_EBP + 8) = iVar4;
    cVar1 = FUN_00492b81(iVar4);
    if (cVar1 == '\0') {
      *(undefined4 *)(extraout_ECX + 0x38) = 6;
      *(undefined1 *)(extraout_ECX + 0x34) = 0xff;
      *(undefined1 *)(extraout_ECX + 0x35) = 0xff;
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      *(undefined1 *)(extraout_ECX + 0x36) = 1;
    }
    else {
      FUN_00492bb0(*(undefined4 *)(unaff_EBP + 8));
      FUN_00492bc4();
    }
    if (*(char *)(unaff_EBP + -0xd) != '\0') {
      FUN_00490a23(DAT_006e57cc);
      FUN_0040766a(0x85,0);
      if (*(int *)(extraout_ECX + 0x54) < 1) {
        pcVar6 = s_Ui_terrain_lower_006c6074;
      }
      else {
        pcVar6 = s_Ui_terrain_raise_006c6088;
      }
      FUN_0057a7f7(pcVar6,0xfffffffc);
      goto LAB_00492198;
    }
  }
LAB_00492146:
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  sVar3 = _strlen(s_altitude_006c4f68);
  FUN_00401a3c(s_altitude_006c4f68,s_altitude_006c4f68 + sVar3);
  *(undefined4 *)(unaff_EBP + -4) = 5;
  FUN_0043168c(unaff_EBP + -0x40);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00401729();
  *(undefined4 *)(extraout_ECX + 0x30) = *(undefined4 *)(unaff_EBP + -0x28);
  FUN_00492c37();
LAB_00492198:
  FUN_00491b2b();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

