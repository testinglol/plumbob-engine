
/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_0057376b(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int extraout_ECX;
  int unaff_EBP;
  bool bVar7;
  char *pcVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  undefined *puVar11;
  
  FUN_00634c24();
  if (((*(char *)(extraout_ECX + 0xe) == '\0') && (*(int *)(unaff_EBP + 8) != 0x22)) ||
     (DAT_006f63bc == '\0')) {
    uVar3 = 1;
    goto LAB_0057443d;
  }
  piVar5 = *(int **)(extraout_ECX + 0x10);
  *(undefined ***)(unaff_EBP + -0x30) = &PTR_LAB_00669c88;
  *(int **)(unaff_EBP + -0x18) = piVar5;
  *(int **)(unaff_EBP + -0x2c) = piVar5;
  (**(code **)(*piVar5 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar3 = FUN_00570d5f();
  piVar5 = (int *)(extraout_ECX + 0xe8);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
  if ((*piVar5 != 5) && (iVar4 = FUN_00570d6a(), iVar4 != DAT_006ceaf0)) {
    uVar3 = 0;
    if (iVar4 < 0x3c1) {
      if (800 < iVar4) {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 2;
    }
    DAT_006ceaf0 = iVar4;
    FUN_0057d094(100,uVar3);
  }
  iVar4 = *(int *)(unaff_EBP + 8);
  if (iVar4 == 0x17) {
    if (*(int *)(unaff_EBP + 0xc) != 0) {
      FUN_0057462e(*(undefined4 *)(unaff_EBP + 0xc));
    }
    goto LAB_0057442f;
  }
  if (iVar4 < 0x21) {
    if (iVar4 == 0x20) {
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_00580a92(unaff_EBP + -0x28);
      iVar4 = *(int *)(unaff_EBP + -0x28);
      *(int *)(unaff_EBP + -0x14) = iVar4;
      *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x24);
      while (iVar4 != 0) {
        if (*(int *)(iVar4 + 8) == *(int *)(unaff_EBP + 0xc)) {
          FUN_0040555d(iVar4 + 4);
        }
        FUN_00576e56();
        iVar4 = *(int *)(unaff_EBP + -0x14);
      }
      puVar6 = *(undefined4 **)(unaff_EBP + -0x3c);
      if (puVar6 != *(undefined4 **)(unaff_EBP + -0x38)) {
        do {
          FUN_005747dc(*puVar6);
          puVar6 = puVar6 + 1;
        } while (puVar6 != *(undefined4 **)(unaff_EBP + -0x38));
        FUN_004071be(*(undefined4 *)(unaff_EBP + -0x3c),*(undefined4 *)(unaff_EBP + -0x38));
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0048c4c9();
      goto LAB_0057442f;
    }
    switch(iVar4) {
    case 1:
      if (*(char *)(extraout_ECX + 0xc) != '\0') {
        uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
        piVar5 = (int *)FUN_00573466(uVar3);
        *(int **)(unaff_EBP + 8) = piVar5;
        if (piVar5 != (int *)0x0) {
          cVar2 = (**(code **)(*piVar5 + 0x70))();
          if (cVar2 == '\0') {
            FUN_005764a8(unaff_EBP + 0xc);
          }
          cVar2 = FUN_00574bdb(*(undefined4 *)(unaff_EBP + 0xc));
          if (cVar2 != '\0') {
            piVar5 = (int *)FUN_00573466(uVar3);
            iVar4 = (**(code **)(*piVar5 + 0x28))();
            if (iVar4 != 2) {
              piVar5 = *(int **)(unaff_EBP + 8);
              (**(code **)(*piVar5 + 0x30))
                        (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                         *(undefined4 *)(unaff_EBP + 0x18));
              iVar4 = *piVar5;
              goto code_r0x005738ff;
            }
            if (*(int *)(unaff_EBP + 0x10) != 0) {
              FUN_00574581(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
              FUN_0057488f(*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + 8,unaff_EBP + -0x10);
              (**(code **)(*piVar5 + 0x30))
                        (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                         *(undefined4 *)(unaff_EBP + 0x18));
              (**(code **)(*piVar5 + 0x40))(*(undefined4 *)(unaff_EBP + 8));
              (**(code **)(*piVar5 + 0x48))(*(undefined4 *)(unaff_EBP + -0x10));
              goto code_r0x005738fb;
            }
          }
        }
      }
      break;
    case 2:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x34))();
      }
      break;
    case 3:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x38))();
      }
      break;
    case 4:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x3c))
                  (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                   *(undefined4 *)(unaff_EBP + 0x18),0);
      }
      break;
    case 5:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      iVar4 = *piVar5;
      uVar3 = *(undefined4 *)(unaff_EBP + 0x10);
      goto code_r0x00574281;
    case 6:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x44))(*(undefined4 *)(unaff_EBP + 0x10));
      break;
    case 7:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x48))(*(undefined4 *)(unaff_EBP + 0x10));
      break;
    case 8:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x4c))
                (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                 *(undefined4 *)(unaff_EBP + 0x18));
      break;
    case 9:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x50))(*(undefined4 *)(unaff_EBP + 0x10));
      break;
    case 10:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x54))(*(undefined4 *)(unaff_EBP + 0x10));
      break;
    case 0xb:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x58))();
      break;
    case 0xc:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x5c))();
      break;
    case 0xd:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x60))();
      break;
    case 0xe:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 100))();
      break;
    case 0xf:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x68))();
      break;
    case 0x10:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x6c))();
      break;
    case 0x11:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      (**(code **)(*piVar5 + 0x84))
                (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),0);
      break;
    case 0x12:
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      if (piVar5 != (int *)0x0) {
        *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0x10);
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          *(undefined4 *)(unaff_EBP + 0xc) = 100;
        }
        iVar4 = *(int *)(unaff_EBP + 0x14);
        (**(code **)(*piVar5 + 0x84))(0x28,0,0);
        (**(code **)(*piVar5 + 0x84))(0x29,0x13,0);
        (**(code **)(*piVar5 + 0x84))(0x2a,*(undefined4 *)(unaff_EBP + 0xc),0);
        *(bool *)((int)piVar5 + 0x1cf) = iVar4 != 0;
        (**(code **)(*piVar5 + 0x84))(0x2d,1,0);
        goto code_r0x00573b72;
      }
      break;
    case 0x13:
code_r0x00573b72:
      piVar5 = (int *)FUN_00573466(0x104);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x9c))();
        piVar5 = (int *)FUN_00573466(0x10d);
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x9c))();
          piVar5 = (int *)FUN_00573466(0x10e);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x9c))();
            piVar5 = (int *)FUN_00573466(0x118);
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 0x9c))();
              piVar5 = (int *)FUN_00573466(0x1a19);
              if (piVar5 != (int *)0x0) {
                (**(code **)(*piVar5 + 0x9c))();
                piVar5 = (int *)FUN_00573466(0x1a1a);
                if (piVar5 != (int *)0x0) {
                  (**(code **)(*piVar5 + 0x9c))();
                  piVar5 = (int *)FUN_00573466(0x1a1b);
                  if (piVar5 != (int *)0x0) {
                    (**(code **)(*piVar5 + 0x9c))();
                    piVar5 = (int *)FUN_00573466(0x1a1c);
                    if (piVar5 != (int *)0x0) {
                      (**(code **)(*piVar5 + 0x9c))();
                      piVar5 = (int *)FUN_00573466(0x1a1d);
                      if (piVar5 != (int *)0x0) {
                        (**(code **)(*piVar5 + 0x9c))();
                        piVar5 = (int *)FUN_00573466(0x18704);
                        if (piVar5 != (int *)0x0) {
                          (**(code **)(*piVar5 + 0x9c))();
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      break;
    case 0x14:
      puVar11 = &DAT_006c08dc;
      pcVar8 = s_cBoxX__kKillAll_006cf070;
      FUN_005bc69b(&DAT_006c08dc);
      FUN_005bc69b(pcVar8);
      FUN_005bc69b(puVar11);
      FUN_0057ceb6();
      FUN_00580a92(unaff_EBP + -0x20);
      FUN_00581ddc(*(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(unaff_EBP + -0x1c),0,
                   extraout_ECX + 0xd4);
      (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x20))();
      (**(code **)(**(int **)(extraout_ECX + 0x104) + 0x20))();
      if (*(int **)(extraout_ECX + 0x108) != (int *)0x0) {
        (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x20))();
      }
      if (*(int **)(extraout_ECX + 0x10c) != (int *)0x0) {
        (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x20))();
      }
      if (*(int **)(extraout_ECX + 0x110) != (int *)0x0) {
        (**(code **)(**(int **)(extraout_ECX + 0x110) + 0x20))();
      }
      *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)(*(int *)(extraout_ECX + 0x14) + 4);
      FUN_0057311d();
      break;
    case 0x15:
      *(undefined1 *)(extraout_ECX + 0xd) = 1;
      FUN_00574972();
      if (*piVar5 == 0) {
        piVar5 = *(int **)(extraout_ECX + 0x100);
code_r0x00573d8d:
        iVar4 = *piVar5;
        uVar9 = 1;
code_r0x0057412e:
        (**(code **)(iVar4 + 0x7c))(uVar9);
      }
      break;
    case 0x16:
      *(undefined1 *)(extraout_ECX + 0xd) = 0;
      if (*(char *)(extraout_ECX + 0xc) != '\0') {
        FUN_00574a58();
        uVar9 = 0;
        iVar4 = **(int **)(extraout_ECX + 0x100);
        goto code_r0x0057412e;
      }
      break;
    case 0x18:
      (**(code **)(*DAT_006fecc4 + 0xa8))();
      break;
    case 0x19:
      bVar7 = *(int *)(unaff_EBP + 0xc) != 0;
      *(bool *)(extraout_ECX + 0xc) = bVar7;
      if (bVar7) {
        puVar6 = (undefined4 *)(extraout_ECX + 0x114);
        *puVar6 = 100;
        FUN_005745d3();
        *puVar6 = 0;
        FUN_005745d3();
        *puVar6 = 100;
        if (*(char *)(extraout_ECX + 0xd) == '\0') {
          FUN_00574a58();
          if (*(int **)(extraout_ECX + 0x100) != (int *)0x0) {
            (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x7c))(0);
          }
        }
        if (*piVar5 == 3) {
          FUN_00574a58();
        }
        FUN_005752a9();
      }
      else if (*piVar5 == 0) {
        (**(code **)(**(int **)(extraout_ECX + 0x104) + 0x7c))(1);
        if (*(int **)(extraout_ECX + 0x108) != (int *)0x0) {
          (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x7c))(1);
        }
        if (*(int **)(extraout_ECX + 0x10c) != (int *)0x0) {
          (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x7c))(1);
        }
        piVar5 = *(int **)(extraout_ECX + 0x110);
        if (piVar5 != (int *)0x0) goto code_r0x00573d8d;
      }
      break;
    case 0x1a:
      (**(code **)(*DAT_006fecc4 + 0xac))(*(undefined4 *)(unaff_EBP + 0xc));
      break;
    case 0x1e:
      FUN_0057462e(*(undefined4 *)(unaff_EBP + 0x10));
      piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_00574581(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10));
      FUN_0057488f(*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + 8,unaff_EBP + -0x10);
      (**(code **)(*piVar5 + 0x30))
                (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                 *(undefined4 *)(unaff_EBP + 0x18));
      (**(code **)(*piVar5 + 0x40))(*(undefined4 *)(unaff_EBP + 8));
      (**(code **)(*piVar5 + 0x48))(*(undefined4 *)(unaff_EBP + -0x10));
      if ((*(char *)(extraout_ECX + 0xd) == '\0') && (*(char *)(extraout_ECX + 0xc) != '\0')) {
code_r0x005738fb:
        iVar4 = *piVar5;
code_r0x005738ff:
        (**(code **)(iVar4 + 0x5c))();
      }
    }
    goto LAB_0057442f;
  }
  if (0x65 < iVar4) {
    if (iVar4 == 0x66) {
      DAT_006f6434 = 0;
    }
    else if (iVar4 == 0x67) {
      FUN_0057cfaa();
    }
    else if (iVar4 == 0x68) {
      (**(code **)(**(int **)(extraout_ECX + 0x10) + 8))();
      FUN_0057311d();
      FUN_00572b70();
      FUN_0057163b(&DAT_006f6388,&DAT_006f6378,&DAT_006f6378);
      (**(code **)(**(int **)(extraout_ECX + 0x10) + 4))();
    }
    else if (iVar4 == 0x69) {
      FUN_005746a7();
    }
    goto LAB_0057442f;
  }
  if (iVar4 == 0x65) {
    FUN_005bc69b(s_Instance_Map_Contents__006cf058);
    FUN_00580a92(unaff_EBP + -0x14);
    while (*(int *)(unaff_EBP + -0x14) != 0) {
      iVar4 = *(int *)(*(int *)(unaff_EBP + -0x14) + 4);
      if (iVar4 != -0x54523502) {
        FUN_00573466(iVar4);
      }
      puVar11 = &DAT_006c3d7c;
      FUN_005bc69b(*(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8));
      FUN_005bc69b(puVar11);
      FUN_00576e56();
    }
    FUN_005bc69b(s_End_of_Instance_Map_Contents_006cf038);
    goto LAB_0057442f;
  }
  switch(iVar4) {
  case 0x21:
    FUN_005745d3();
    iVar4 = FUN_00570d92();
    if ((*(int *)(DAT_006f6a78 + 0x28) != 0) || (iVar4 < 0x1e)) {
      iVar4 = 0;
    }
    if (*(int **)(extraout_ECX + 0x100) != (int *)0x0) {
      (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x30))(iVar4 * 10);
      iVar4 = FUN_00570fb5(0,4);
      (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x34))
                ((*(int *)(iVar4 * 4 + 0x6ceaf4) * 1000) / 0xd);
    }
    goto code_r0x0057430b;
  case 0x22:
    bVar7 = *(int *)(unaff_EBP + 0xc) != 0;
    *(bool *)(extraout_ECX + 0xe) = bVar7;
    if (!bVar7) {
      FUN_0057ceb6();
    }
    break;
  case 0x23:
    iVar4 = *(int *)(unaff_EBP + 0xc);
    *(bool *)(extraout_ECX + 0xf) = *(int *)(unaff_EBP + 0xc) != 0;
    (**(code **)(*DAT_006fecc4 + 0x24))(iVar4 == 0);
    break;
  case 0x24:
    func_0x005752c4(*(undefined4 *)(unaff_EBP + 0xc));
    if (*piVar5 == 0) {
      if (*(int **)(extraout_ECX + 0x100) != (int *)0x0) {
        (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x18))();
        uVar9 = *(undefined1 *)(extraout_ECX + 0xd);
        iVar4 = **(int **)(extraout_ECX + 0x100);
code_r0x00574167:
        (**(code **)(iVar4 + 0x7c))(uVar9);
      }
    }
    else {
      if (*piVar5 == 3) {
        piVar5 = *(int **)(extraout_ECX + 0x100);
        if (piVar5 != *(int **)(extraout_ECX + 0x104)) {
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x20))();
          }
          *(int *)(extraout_ECX + 0x100) = *(int *)(extraout_ECX + 0x104);
        }
        (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x30))(1000);
        (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x34))(500);
        (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x18))();
        uVar9 = 0;
        iVar4 = **(int **)(extraout_ECX + 0x100);
        goto code_r0x00574167;
      }
      if (*(int **)(extraout_ECX + 0x100) != (int *)0x0) {
        (**(code **)(**(int **)(extraout_ECX + 0x100) + 0x20))();
      }
    }
    goto code_r0x0057430b;
  case 0x25:
    iVar4 = *(int *)(unaff_EBP + 0xc);
    *(int *)(extraout_ECX + 0xf0) = iVar4;
    uVar3 = *(undefined4 *)(&DAT_0067156c + iVar4 * 4);
    piVar5 = (int *)FUN_0057c0ff(1);
    (**(code **)(*piVar5 + 0x40))(uVar3);
    (**(code **)(**(int **)(extraout_ECX + 0x104) + 0x24))(uVar3);
    if (*(int **)(extraout_ECX + 0x108) != (int *)0x0) {
      (**(code **)(**(int **)(extraout_ECX + 0x108) + 0x24))(uVar3);
    }
    if (*(int **)(extraout_ECX + 0x10c) != (int *)0x0) {
      (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x24))(uVar3);
    }
    if (*(int **)(extraout_ECX + 0x110) != (int *)0x0) {
      (**(code **)(**(int **)(extraout_ECX + 0x110) + 0x24))(uVar3);
    }
code_r0x0057430b:
    FUN_00574acc();
    break;
  case 0x26:
    iVar4 = *(int *)(unaff_EBP + 0xc);
    uVar10 = 2;
    *(int *)(extraout_ECX + 0xf4) = iVar4;
    uVar3 = *(undefined4 *)(&DAT_0067156c + iVar4 * 4);
    goto code_r0x00574273;
  case 0x27:
    iVar4 = *(int *)(unaff_EBP + 0xc);
    uVar10 = 3;
    *(int *)(extraout_ECX + 0xf8) = iVar4;
    uVar3 = *(undefined4 *)(&DAT_0067156c + iVar4 * 4);
code_r0x00574273:
    piVar5 = (int *)FUN_0057c0ff(uVar10);
    iVar4 = *piVar5;
code_r0x00574281:
    (**(code **)(iVar4 + 0x40))(uVar3);
    break;
  case 0x28:
    uVar3 = *(undefined4 *)(extraout_ECX + 0xf0);
    goto code_r0x005742a1;
  case 0x29:
    uVar3 = *(undefined4 *)(extraout_ECX + 0xf4);
    goto code_r0x005742a1;
  case 0x2a:
    uVar3 = *(undefined4 *)(extraout_ECX + 0xf8);
code_r0x005742a1:
    **(undefined4 **)(unaff_EBP + 0xc) = uVar3;
    break;
  case 0x2b:
    piVar5 = (int *)FUN_00573466(0x772);
    if (piVar5 != (int *)0x0) {
      FUN_0057320a(*(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + 0x14,unaff_EBP + 0x18,piVar5);
      (**(code **)(*piVar5 + 0x2c))
                (*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                 *(undefined4 *)(unaff_EBP + 0x18));
      uVar3 = (**(code **)(*piVar5 + 0x24))();
      *(undefined4 *)(unaff_EBP + 0xc) = 0x772;
      FUN_005764a8(unaff_EBP + 0xc);
      FUN_00574581(*(undefined4 *)(unaff_EBP + 0xc),uVar3);
      FUN_00570d5f();
      uVar3 = FUN_00570fb5(*(undefined4 *)(unaff_EBP + 0x10),5);
      piVar5 = (int *)FUN_00573466(0x773);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x2c))(uVar3,0,0);
      }
    }
    break;
  case 0x2c:
    uRam006f63ce = 1;
    break;
  case 0x2d:
    uRam006f63ce = 0;
    break;
  case 0x2e:
    DAT_006f63cf = 1;
    break;
  case 0x2f:
    DAT_006f63cf = 0;
    break;
  case 0x30:
    uRam006f63d0 = 1;
    break;
  case 0x31:
    uRam006f63d0 = 0;
    break;
  case 0x34:
    iVar4 = *(int *)(unaff_EBP + 0xc);
    piVar5 = (int *)0x0;
    if (iVar4 == 0) {
      piVar5 = *(int **)(extraout_ECX + 0x104);
    }
    else if (iVar4 == 1) {
      piVar5 = *(int **)(extraout_ECX + 0x108);
    }
    else if (iVar4 == 2) {
      piVar5 = *(int **)(extraout_ECX + 0x10c);
    }
    else if (iVar4 == 3) {
      piVar5 = *(int **)(extraout_ECX + 0x110);
    }
    piVar1 = *(int **)(extraout_ECX + 0x100);
    if (piVar5 != piVar1) {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x20))();
      }
      *(int **)(extraout_ECX + 0x100) = piVar5;
      (**(code **)(*piVar5 + 0x18))();
      uVar9 = *(undefined1 *)(extraout_ECX + 0xd);
      iVar4 = **(int **)(extraout_ECX + 0x100);
      goto code_r0x0057412e;
    }
    break;
  case 0x35:
    piVar5 = (int *)FUN_00573466(*(undefined4 *)(unaff_EBP + 0xc));
    if (piVar5 != (int *)0x0) {
      puVar6 = (undefined4 *)FUN_0057d4e4(*(undefined4 *)(unaff_EBP + 0x14));
      uVar3 = (**(code **)*puVar6)();
      (**(code **)(*piVar5 + 0xa8))(uVar3);
    }
  }
LAB_0057442f:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(**(int **)(unaff_EBP + -0x18) + 8))();
  uVar3 = 0;
LAB_0057443d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

