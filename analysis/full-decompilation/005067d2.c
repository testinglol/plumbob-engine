
void FUN_005067d2(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int extraout_ECX;
  int unaff_EBP;
  int iVar5;
  undefined4 uVar6;
  undefined *puVar7;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_004d26ba(*(undefined4 *)(*(int *)(extraout_ECX + 0xd4) + 0x54),unaff_EBP + -0x14,
               unaff_EBP + -0x10);
  if (*(int *)(extraout_ECX + 0x46c) == 0) {
    (**(code **)(**(int **)(extraout_ECX + 0x1cc) + 0x98))();
  }
  else {
    (**(code **)(**(int **)(extraout_ECX + 0x1cc) + 0x94))();
    iVar5 = *(int *)(unaff_EBP + 8);
    if (iVar5 == 0) {
      iVar5 = **(int **)(extraout_ECX + 0x1cc);
      uVar6 = *(undefined4 *)
               (extraout_ECX + 0xec + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xa8) * 4);
    }
    else if (iVar5 == 1) {
      iVar5 = **(int **)(extraout_ECX + 0x1cc);
      uVar6 = *(undefined4 *)
               (extraout_ECX + 0x10c + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) * 4);
    }
    else if (iVar5 == 2) {
      iVar5 = **(int **)(extraout_ECX + 0x1cc);
      uVar6 = *(undefined4 *)
               (extraout_ECX + 300 + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb8) * 4);
    }
    else if (iVar5 == 3) {
      iVar5 = **(int **)(extraout_ECX + 0x1cc);
      uVar6 = *(undefined4 *)
               (extraout_ECX + 0x14c + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xc0) * 4);
    }
    else if (iVar5 == 4) {
      iVar5 = **(int **)(extraout_ECX + 0x1cc);
      uVar6 = *(undefined4 *)
               (extraout_ECX + 0x16c + *(int *)(*(int *)(extraout_ECX + 0xd4) + 200) * 4);
    }
    else if (iVar5 == 5) {
      iVar5 = **(int **)(extraout_ECX + 0x1cc);
      uVar6 = *(undefined4 *)
               (extraout_ECX + 0x18c + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xd0) * 4);
    }
    else {
      if (iVar5 != 6) goto LAB_0050693a;
      iVar5 = **(int **)(extraout_ECX + 0x1cc);
      uVar6 = *(undefined4 *)
               (extraout_ECX + 0x1ac + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xd8) * 4);
    }
    (**(code **)(iVar5 + 0x19c))(uVar6,4,1);
  }
LAB_0050693a:
  iVar5 = 0;
  do {
    piVar1 = (int *)(extraout_ECX + 0x400 + iVar5 * 4);
    (**(code **)(**(int **)(extraout_ECX + 0x400 + iVar5 * 4) + 0x94))();
    piVar2 = (int *)*piVar1;
    if ((char)piVar2[0x5a] != '\x01') {
      *(undefined1 *)(piVar2 + 0x5a) = 1;
      (**(code **)(*piVar2 + 0x168))();
    }
    iVar3 = *(int *)(unaff_EBP + 8);
    if (iVar3 == 0) {
      if (*(int *)(extraout_ECX + 0x46c) != 0) {
        (**(code **)(*(int *)*piVar1 + 0x19c))
                  (*(undefined4 *)(extraout_ECX + 0x1f0 + iVar5 * 4),4,1);
        FUN_004cb21d((&DAT_006f3540)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                     (&DAT_006f3544)[iVar5 * 2]);
        FUN_005dd9c8(&DAT_006f3000 + iVar5 * 0xc);
        cVar4 = (&DAT_006f2d98)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xa8) * 8 + iVar5];
        goto LAB_0050705b;
      }
      (**(code **)(*(int *)*piVar1 + 0x19c))(*(undefined4 *)(extraout_ECX + 0x1d0 + iVar5 * 4));
      FUN_004cb21d((&DAT_006f3580)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                   (&DAT_006f3584)[iVar5 * 2]);
      puVar7 = &DAT_006f2fa0 + iVar5 * 0xc;
LAB_00506db8:
      FUN_005dd9c8(puVar7);
    }
    else if (iVar3 == 1) {
      if (*(int *)(extraout_ECX + 0x46c) == 0) {
        (**(code **)(*(int *)*piVar1 + 0x19c))
                  (*(undefined4 *)(extraout_ECX + 0x350 + iVar5 * 4),4,1);
        FUN_004cb21d((&DAT_006f3500)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                     (&DAT_006f3504)[iVar5 * 2]);
        puVar7 = &DAT_006f3000 + iVar5 * 0xc;
        goto LAB_00506db8;
      }
      if (-1 < iVar5) {
        if (iVar5 < 4) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)
                      (extraout_ECX +
                      (iVar5 + 0xdc + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) * 4) * 4),4,1);
          FUN_005dd9c8(&DAT_006f2e18 +
                       (iVar5 + *(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) * 4) * 0xc);
          cVar4 = (&DAT_006f2d58)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) * 8 + iVar5];
        }
        else if (iVar5 == 4) {
          if (*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) != 7) {
            (**(code **)(*(int *)*piVar1 + 0x98))();
            FUN_005d4956(&DAT_006de560);
            *(undefined4 *)(unaff_EBP + -4) = 0;
            FUN_005dd9c8(unaff_EBP + -0x2c);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00506ebf:
            FUN_005b8770();
            goto LAB_00506fad;
          }
          (**(code **)(*(int *)*piVar1 + 0x19c))(*(undefined4 *)(extraout_ECX + 0x3f0),4,1);
          FUN_005dd9c8(&DAT_006f2de8);
          cVar4 = (&DAT_006f2d5c)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) * 8];
        }
        else if (iVar5 == 5) {
          if (*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) != 7) {
            (**(code **)(*(int *)*piVar1 + 0x98))();
            FUN_005d4956(&DAT_006de560);
            *(undefined4 *)(unaff_EBP + -4) = 1;
            FUN_005dd9c8(unaff_EBP + -0x20);
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            goto LAB_00506ebf;
          }
          (**(code **)(*(int *)*piVar1 + 0x19c))(*(undefined4 *)(extraout_ECX + 0x3f4),4,1);
          FUN_005dd9c8(&DAT_006f2dd8);
          cVar4 = (&DAT_006f2d5d)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) * 8];
        }
        else {
          if (iVar5 != 6) {
            if (iVar5 == 7) {
              (**(code **)(*(int *)*piVar1 + 0x19c))(*(undefined4 *)(extraout_ECX + 0x3fc),4,1);
              FUN_005dd9c8(&DAT_006f2df8);
            }
            goto LAB_00506fad;
          }
          (**(code **)(*(int *)*piVar1 + 0x19c))(*(undefined4 *)(extraout_ECX + 0x3f8),4,1);
          FUN_005dd9c8(&DAT_006f2e08);
          cVar4 = (&DAT_006f2d5e)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb0) * 8];
        }
        piVar1 = (int *)*piVar1;
        if ((char)piVar1[0x5a] != cVar4) {
          *(char *)(piVar1 + 0x5a) = cVar4;
          (**(code **)(*piVar1 + 0x168))();
        }
      }
LAB_00506fad:
      FUN_004cb21d((&DAT_006f34c0)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                   (&DAT_006f34c4)[iVar5 * 2]);
    }
    else {
      if (iVar3 == 2) {
        if (*(int *)(extraout_ECX + 0x46c) != 0) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x2b0 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f3340)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f3344)[iVar5 * 2]);
          FUN_005dd9c8(&DAT_006f3000 + iVar5 * 0xc);
          cVar4 = (&DAT_006f2d18)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xb8) * 8 + iVar5];
LAB_0050705b:
          piVar1 = (int *)*piVar1;
          if ((char)piVar1[0x5a] != cVar4) {
            *(char *)(piVar1 + 0x5a) = cVar4;
            (**(code **)(*piVar1 + 0x168))();
          }
          goto LAB_00507075;
        }
        if (((iVar5 != 4) && (iVar5 != 5)) && (iVar5 != 6)) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x210 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f3480)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f3484)[iVar5 * 2]);
          puVar7 = &DAT_006f3060 + iVar5 * 0xc;
          goto LAB_00506db8;
        }
      }
      else if (iVar3 == 3) {
        if (*(int *)(extraout_ECX + 0x46c) != 0) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x2d0 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f3280)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f3284)[iVar5 * 2]);
          FUN_005dd9c8(&DAT_006f3000 + iVar5 * 0xc);
          cVar4 = (&DAT_006f2cd8)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xc0) * 8 + iVar5];
          goto LAB_0050705b;
        }
        if (((iVar5 != 4) && (iVar5 != 5)) && (iVar5 != 6)) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x230 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f3400)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f3404)[iVar5 * 2]);
          puVar7 = &DAT_006f30c0 + iVar5 * 0xc;
          goto LAB_00506db8;
        }
      }
      else if (iVar3 == 4) {
        if (*(int *)(extraout_ECX + 0x46c) != 0) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x2f0 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f3240)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f3244)[iVar5 * 2]);
          FUN_005dd9c8(&DAT_006f3000 + iVar5 * 0xc);
          cVar4 = (&DAT_006f2c98)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 200) * 8 + iVar5];
          goto LAB_0050705b;
        }
        if (((iVar5 != 4) && (iVar5 != 5)) && (iVar5 != 6)) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x250 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f33c0)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f33c4)[iVar5 * 2]);
          puVar7 = &DAT_006f3120 + iVar5 * 0xc;
          goto LAB_00506db8;
        }
      }
      else {
        if (iVar3 != 5) {
          if (iVar3 == 6) {
            if (*(int *)(extraout_ECX + 0x46c) != 0) {
              (**(code **)(*(int *)*piVar1 + 0x19c))
                        (*(undefined4 *)(extraout_ECX + 0x330 + iVar5 * 4),4,1);
              FUN_004cb21d((&DAT_006f32c0)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                           (&DAT_006f32c4)[iVar5 * 2]);
              FUN_005dd9c8(&DAT_006f3000 + iVar5 * 0xc);
              cVar4 = (&DAT_006f2c18)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xd8) * 8 + iVar5];
              goto LAB_0050705b;
            }
            if (((iVar5 == 4) || (iVar5 == 5)) || (iVar5 == 6)) goto LAB_00506d0e;
            (**(code **)(*(int *)*piVar1 + 0x19c))
                      (*(undefined4 *)(extraout_ECX + 0x290 + iVar5 * 4),4,1);
            FUN_004cb21d((&DAT_006f3380)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                         (&DAT_006f3384)[iVar5 * 2]);
            FUN_005dd9c8(&DAT_006f3180 + iVar5 * 0xc);
            if (iVar5 == 3) {
              FUN_005dd9c8(&DAT_006f3138);
            }
            if (iVar5 == 2) {
              puVar7 = &DAT_006f31b0;
              goto LAB_00506db8;
            }
          }
          goto LAB_00507075;
        }
        if (*(int *)(extraout_ECX + 0x46c) != 0) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x310 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f3300)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f3304)[iVar5 * 2]);
          FUN_005dd9c8(&DAT_006f3000 + iVar5 * 0xc);
          cVar4 = (&DAT_006f2c58)[*(int *)(*(int *)(extraout_ECX + 0xd4) + 0xd0) * 8 + iVar5];
          goto LAB_0050705b;
        }
        if (((iVar5 != 4) && (iVar5 != 5)) && (iVar5 != 6)) {
          (**(code **)(*(int *)*piVar1 + 0x19c))
                    (*(undefined4 *)(extraout_ECX + 0x270 + iVar5 * 4),4,1);
          FUN_004cb21d((&DAT_006f3440)[iVar5 * 2] - *(int *)(unaff_EBP + -0x14),
                       (&DAT_006f3444)[iVar5 * 2]);
          puVar7 = &DAT_006f3180 + iVar5 * 0xc;
          goto LAB_00506db8;
        }
      }
LAB_00506d0e:
      (**(code **)(*(int *)*piVar1 + 0x98))();
    }
LAB_00507075:
    iVar5 = iVar5 + 1;
    if (7 < iVar5) {
      FUN_004cb21d(DAT_006f35c0 - *(int *)(unaff_EBP + -0x14),DAT_006f35c4);
      FUN_004cb21d((*(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c)) + -0x18,
                   DAT_006f35cc);
      FUN_004cb21d(0xfffffffe,
                   (((*(int *)(*(int *)(extraout_ECX + 0x1cc) + 0x80) -
                     *(int *)(*(int *)(extraout_ECX + 0x1cc) + 0x88)) -
                    *(int *)(extraout_ECX + 0x80)) + *(int *)(extraout_ECX + 0x88)) / 2);
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
  } while( true );
}

