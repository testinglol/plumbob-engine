
void __fastcall FUN_005e73a3(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00674354;
  if ((HCURSOR)param_1[1] != (HCURSOR)0x0) {
    DestroyCursor((HCURSOR)param_1[1]);
    param_1[1] = 0;
  }
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[2])(1);
  }
  if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[3])(1);
  }
  return;
}

