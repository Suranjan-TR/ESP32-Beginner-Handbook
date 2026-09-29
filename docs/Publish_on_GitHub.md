# How to Publish This Handbook on GitHub

## One-time setup
1. Install **Git for Windows**: https://git-scm.com/download/win
2. Create a free account at https://github.com
3. Tell Git who you are (open **Git Bash** or PowerShell):
   ```
   git config --global user.name "Your Name"
   git config --global user.email "you@example.com"
   ```

## Create the repository on GitHub
1. Click **+ → New repository**.
2. Name: `ESP32-Beginner-Handbook`. Choose **Public**.
3. **Do not** tick "Add a README" or a licence (the project already has them).
4. Click **Create repository** and copy the URL, e.g. `https://github.com/YOUR-USERNAME/ESP32-Beginner-Handbook.git`.

## Upload the project
Unzip the ZIP, open a terminal **inside** the `ESP32-Beginner-Handbook` folder:
```
git init
git add .
git commit -m "Add ESP32 Beginner Handbook"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/ESP32-Beginner-Handbook.git
git push -u origin main
```
GitHub may ask you to sign in in the browser (or use a Personal Access Token as the password).

**No command line?** On the repository page choose **Add file → Upload files** and drag the *contents* of the folder (folders included). GitHub allows dragging folders in the browser.

## Update later
```
git add .
git commit -m "Describe your change"
git push
```

## Check after publishing
- The Mermaid diagrams render automatically on GitHub.
- The SVG diagrams appear via relative paths; open a chapter and check the images.
- Replace `[Instructor Name / Institution]` in `LICENSE` and the placeholders in `README.md`.
- Optional: repository **Settings → Pages** can publish the docs as a website.

## Sharing with students
Send the repository link. Students can click **Code → Download ZIP** or `git clone` it.
